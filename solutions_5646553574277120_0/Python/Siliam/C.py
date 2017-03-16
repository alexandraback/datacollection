B = dict()

import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

def canBuy(v, D, K):
    if v in B.keys() :
        return B[v]
    
    for k in xrange(1, D + 1):
        for s in findsubsets(K, k):
            if v == sum(s):
                B[v] = True
                return True
    B[v] = False
    return False

if __name__ == '__main__':
    f = open('C-small-attempt1.in', 'r')
    o = open('C-small-attempt1.out', 'w')

    T = int(f.readline())
    
    for testCase in xrange(1, T + 1):
        B = {}
        C, D, V = map(int, f.readline().split())
        K = map(int, f.readline().split())
        r = 0
        
        for v in xrange(1, V+1):
            if not canBuy(v, D, K):
                # print "Adding :", v
                K.append(v)
                D += 1
                r += 1
        
        #print K
        #print ('Case #' + str(testCase) + ': ' + str(r))
        o.write('Case #' + str(testCase) + ': ' + str(r) +'\n')
    o.close()