#!/usr/bin/env python

def main():
    f = open('input.txt', 'r')
    total_T = int(f.readline())
    #print total_T

    R, N, M, K = f.readline().split()
    R = int(R)
    N = int(N)
    M = int(M)
    K = int(K)
    print "Case #1:"
    for r in xrange(R):
        pro = f.readline().split()
        pro = map(int, pro)
        use = [0] * len(pro)
        cadidate = []
        # print pro


        while remove_able(pro, 5):
            cadidate.append(5)
            remove_m(pro, 5)
        while remove_able(pro, 3):
            cadidate.append(3)
            remove_m(pro, 3)
        while remove_able(pro, 4):
            cadidate.append(4)
            remove_m(pro, 4)

        if any(x==2 for x in pro):
            cadidate.append(2)
            remove_m(pro, 2)


        # print pro
        # print use
        # print remove_able(pro, 2)

        try:
            while len(cadidate) < N:
                cadidate.append(min(cadidate))
        except Exception, e:
            cadidate = [2] * N


        print ''.join(map(str,cadidate))



def check(pro, m):
    if any([x/m*m==x for x in pro]):
        return True
    return False

def remove_able(pro, m):
    for x in xrange(len(pro)):
        y = pro[x]
        if y/m*m==y:
            y = y/m
            return True
    return False


def remove_m(pro, m):
    for x in xrange(len(pro)):
        if pro[x]/m*m==pro[x]:
            pro[x] = pro[x] /m

class Node(object):
    def __init__(self, string):
        self.string = string

        self.T = int(string.split()[0])
        the_list = string.split()
        the_list = map(int, the_list)
        the_list = the_list[1:]
        self.the_even = the_list[::2]
        self.the_odd = the_list[1::2]
        self.likes = zip(self.the_even, self.the_odd)
        self.satisfied = False

    def num_malted(self):
        return sum(the_odd)

    def __repr__(self):
        return "{},{}".format(self.T, self.likes)



if __name__ == '__main__':
    main()