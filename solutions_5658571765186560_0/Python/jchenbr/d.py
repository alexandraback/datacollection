#!/usr/bin/python
import sys


class Omino:

    def __init__(self, data):
        N = n = data[0][0];
        M = m = data[0][1];

        for item in data:
            n = min(n, item[0])
            N = max(N, item[0])
            m = min(m, item[1])
            M = max(M, item[1])

        self.data = [];

        for item in data:
            self.data.append((item[0] - n, item[1] - m));

        self.data.sort();
        self.N = N - n;
        self.M = M - m;

    def __cmp__(self, other):
        return cmp(self.data, other.data)

    def _eq__(self, other):
        return self.data == other.data

    def rotate(self):
        data = [];
        for item in self.data:
            data.append((self.N - item[1] , item[0]))

        return Omino(data)
    
    def yflip(self):
        data = [];
        for item in self.data:
            data.append((self.N - item[0] , item[1]))
        
        return Omino(data)

    def xflip(self):
        data = [];
        for item in self.data:
            data.append((item[0], self.M - item[1] ))
            
        return Omino(data)
        
    def grow(self):
        ret = list()

        for item in self.data:
            for it_ in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                one = (item[0] - it_[0], item[1] - it_[1])
                if (one not in self.data):
                    ret.append(Omino(self.data + [one]))
        return ret;
                


shape = list()
shape.append([Omino( [(0,0)] )]);


for idx in range(1, 7):
    to_add = list()
    print >> sys.stderr, "shape length = ", len(shape)
    for item in shape[idx - 1]:
        for new_item in item.grow():
            flag = True
            for count in range(4):
                if new_item in to_add or \
                        new_item.xflip() in to_add or \
                        new_item.yflip() in to_add:
                    flag = False
                new_item = new_item.rotate()
            if flag:
                to_add.append(new_item)
                if (idx <= 0):
                    print new_item.data


    shape.append(to_add)
    print >> sys.stderr, "idx = ", idx, "to_add = ", len(to_add)

def Cover(x, y, R, C, f, shape):
    if (x + shape.N >= R) or (y + shape.M >= C):
        return False;

    for item in shape.data:
        if f[item[0] + x][item[1] + y]:
            return False;

    for item in shape.data:
        f[item[0] + x][item[1] + y] = True

    return True;

def Recover(x, y, f, shape):
    for item in shape.data:
        f[item[0] + x][item[1] + y] = False

def TryFill(center, template, R, C, xbeg, ybeg, f, residual, nShape):

    xbeg += ybeg / C;
    ybeg %= C;

    print >> sys.stderr, "Now, residul = ", residual, type(center) , "board:"
    #print >> sys.stderr, "beg " , (xbeg,ybeg)

    #for line in f:
    #    print >> sys.stderr, line
        
    if residual == 0 and type(center) == type(False):
        return True


    for x in xrange(xbeg, R):
        if x != xbeg:
            ybeg = 0
        for y in xrange(ybeg, C):
            if center and Cover(x, y, R, C, f, center):
                if TryFill(False, template, 
                        R, C, x , y + 1, 
                        f, residual - nShape, nShape):
                    return True
                Recover(x, y, f, center)

            for temp in template:
                #print >> sys.stderr, "try template", temp.data, "@",(x,y),"="
                if Cover(x, y, R, C, f, temp):
                    if TryFill(center, template,
                            R, C, x, y + 1,
                            f, residual - nShape, nShape):
                        return True
                    Recover(x, y, f, temp)

    return False

def Explore(nShape, R, C):

    for center in shape[nShape - 1]:
        flag = False   

        print >> sys.stderr, "Center = ", center.data, center.N, center.M

        template = list()
        for u in shape[nShape - 1]:
            for count in range(4):
                if u not in template:
                    template.append(u)
                if u.xflip() not in template:
                    template.append(u.xflip())
                if u.yflip() not in template:
                    template.append(u.yflip())
                u = u.rotate()
            
        f = [[False for j in range(C)] for i in range(R)]
        if not TryFill(center, template, R, C, 0, 0, f, R*C, nShape):
            return False

    return True



if __name__ == "__main__":

    try:
        fin = open(sys.argv[1], 'r')
        pass
    except IOError as e:
        print "Can't open the input file."

    data = fin.readlines();
    total = int(data[0])

    for case in range(1, total + 1):
        X, R, C = [int(item) for item in data[case].split()]

        if (X > 6) or (X > R and X > C) or (C*R % X != 0) or \
                not (Explore(X , R, C) or Explore(X, C, R)):
            #print (X > 6) , (X > R and X > C) , (C*R % X != 0);
            print "Case #" + str(case) + ": RICHARD"
        else:
            print "Case #" + str(case) + ": GABRIEL"

