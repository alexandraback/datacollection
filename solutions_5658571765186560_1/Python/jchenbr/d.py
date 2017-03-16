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

    def getCode(self, x, y, R, C):
        ret = 0;
        for item in self.data:
            if (x + item[0] >= C):
                return 0
            ret |= 1 << ((x + item[0]) * C + y + item[1]);
        return ret;

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


    shape.append(to_add)
    print >> sys.stderr, "idx = ", idx, "to_add = ", len(to_add)

def Cover(x, y, R, C, f, shape):
    

    for item in shape.data:
        f[item[0] + x][item[1] + y] = True

    return True;

def Recover(x, y, f, shape):
    for item in shape.data:
        f[item[0] + x][item[1] + y] = False

def Hash(f, center):
    ret = (type(center) == type(False)) * 1;
    for line in f:
        for item in line:
            ret = (ret << 1) + item;
    return ret;

def TryFill(has, center, template, R, C, xbeg, ybeg, f, residual, nShape):


    xbeg += ybeg / C;
    ybeg %= C;

    FullTest = (1 << (xbeg * C + ybeg) ) - 1;

    if (FullTest & f) != FullTest:
        return False
    
    hashCode = (f << 1) | (type(center)== type(False))
    #print >> sys.stderr, "f = {0:b}" .format(f) , ", now = {0:b}".format(hashCode) ,
    #print >> sys.stderr, "residual = " , residual, type(center)


    if (hashCode in has):
        return False
    else:
        has.add(hashCode)

        
    if residual == 0 and type(center) == type(False):
        return True


    lim = 1 << (R * C);
    for x in xrange(xbeg, R):
        if x != xbeg:
            ybeg = 0
        for y in xrange(ybeg, C):
            if type(center) != type(False) :
                now = center.getCode(x, y, R, C)

                if now and (now < lim) and (now & f) == 0:
                    f |= now
                    #print >>sys.stderr, "center," ,(x, y), "now = {0:b}".format(now)

                    if TryFill(has, False, template, 
                            R, C, x , y + 1, 
                            f, residual - nShape, nShape):
                        return True

                    f ^= now
                

            for temp in template:
                #print >> sys.stderr, "try template", temp.data, "@",(x,y),"="
                now = temp.getCode(x, y, R, C)
                if now and (now < lim) and (now & f) == 0:
                    #print  >>sys.stderr, "templa,",(x, y), "now = {0:b}".format(now)
                    f |= now
                    if TryFill(has, center, template,
                            R, C, x, y + 1,
                            f, residual - nShape, nShape):
                        return True
                    
                    f ^= now
            if ((f >> (x * C + y)) & 1) == 0:
                return False

    return False



def Explore_(nShape, R, C):
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
            
        if not TryFill(set(), center, template, R, C, 0, 0, 0, R*C, nShape):
            return False

    return True

def Visit(f, x, y):
    if x < 0 or x >= len(f) or y < 0 or y >= len(f[0]):
        return 0;

    if (f[x][y]) :
        return 0;

    f[x][y] = True
    ret = 1
    ret += Visit(f, x + 0, y + 1)
    ret += Visit(f, x + 0, y - 1)
    ret += Visit(f, x + 1, y + 0)
    ret += Visit(f, x - 1, y + 0)
    return ret


def Explore(X, R, C):

    if (X > 6) or (X > R and X > C) or (R * C % X != 0):
        return False

    for center in shape[X - 1]:
        flag = False;

        for x in range(R - center.N):
            for y in range(C - center.M):
                
                f = [[(i - x,j - y) in center.data for j in range(C)] for i in range(R)] 
                
                if (X, R, C) == (3, 3, 2):
                    for line in f:
                        print >> sys.stderr, line
            
                flag_now = True;
                for i in range(R):
                    for j in range(C):
                        if Visit(f, i, j) % X != 0:
                            flag_now = False 

                flag = flag or flag_now

        for x in range(C - center.N):
            for y in range(R - center.M):
                
                f = [[(i - x,j - y) in center.data for j in range(R)] for i in range(C)] 
                
                if (X, R, C) == (3, 3, 2):
                    for line in f:
                        print >> sys.stderr, line
            
                flag_now = True;
                for i in range(C):
                    for j in range(R):
                        if Visit(f, i, j) % X != 0:
                            flag_now = False 

                flag = flag or flag_now



        if (X, R, C) == (3, 3, 2):
            print >> sys.stderr, center.data, flag

        if not flag:
            return False
    return flag;

history = [[] for i in range(0, 7)]

def Prepare(X, N, M):

    if (X > 6) or (X > N and X > M) or (N * M % X != 0):
        return False

    if (N, M) not in history[X]:
        print >> sys.stderr, "(N,M,X)", N, M, X
        if Explore(X, N, M):
            history[X].append((N,M))

if __name__ == "__main__":

    try:
        fin = open(sys.argv[1], 'r')
        pass
    except IOError as e:
        print "Can't open the input file."

    data = fin.readlines();
    total = int(data[0])

    for case in range(1 , total + 1):
        X, R, C = [int(item) for item in data[case].split()]

        if not Explore(X, R, C):
            print "Case #" + str(case) + ": RICHARD"
        else:
            print "Case #" + str(case) + ": GABRIEL"

