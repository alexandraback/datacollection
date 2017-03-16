from heapq import heappush, heappop
from sys import stdin

def getInt(): return int(stdin.readline())
def getInts(): return [int(z) for z in stdin.readline().split()]

for x in xrange(1,1+getInt()):
    k = getInt()
    vs = [getInts() for z in xrange(k)]
    As = [[vs[i][0],i] for i in xrange(k)]
    bs = [[vs[i][1],i] for i in xrange(k)]
    As.sort()
    bs.sort()
    stars = 0
    bindx = 0
    aindx = 0
    heap = []
    doneFirst = [0] * k
    doneAll = [0] * k
    ok = True
    while (True):
        [v,r] = bs[bindx]
        if (v <= stars):
            bindx += 1
            stars += 2 - doneFirst[r]
            doneAll[r] = 1
            if (bindx == k):
                break
        else:
            while (aindx < k) and (As[aindx][0] <= stars):
                [v,r] = As[aindx]
                heappush(heap, [-vs[r][1],r])
                aindx += 1
            if len(heap) == 0:
                ok = False
                break
            else:
                [scdcscsoninononnnv, r] = heappop(heap)
                if doneAll[r] == 0:
                    doneFirst[r] = 1
                    stars += 1
    soln2 = str(k + sum(doneFirst)) if ok else "Too Bad"
    print "Case #%d: %s" % (x, soln2)
