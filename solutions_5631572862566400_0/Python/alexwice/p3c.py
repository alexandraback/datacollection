from itertools import permutations
#from time import time
def solve(N,A):
    #sigh, lets brute force for 16pts
    #A = dict(enumerate(A))

    ans = 0
    #t = time()
    for cand in permutations(range(1,N)):#3.6 million
        cand = (0,)+cand
        for sz in xrange(1,N+1):
            if sz <= ans: continue
            if all( A[cand[i]] in [cand[(i-1)%sz], cand[(i+1)%sz]]
                    for i in xrange(sz)):
                ans = max(ans,sz)
    #print 'time', time()-t
    return ans
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = map(lambda x: int(x)-1, rr().split())
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
