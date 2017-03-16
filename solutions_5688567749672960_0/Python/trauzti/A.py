import sys
from Queue import Queue

from heapq import heappush, heappop


costd = {1: 1}

def shortest(dest):
    cnt = 0
    k = 0
    # number and cost
    Q = Queue()
    Q.put(1)
    done = set()

    while Q:
        k = Q.get()

        if k <= dest and k not in done:
            done.add(k)

        if len(done) == dest:
            break

        revs = str(k)[::-1]
        rev = int(revs)

        if rev not in costd:
            costd[rev] = 1+ costd[k]
            Q.put(rev)


        if k+1 not in costd:
            costd[k+1] = 1+ costd[k]
            Q.put(k+1)


    return costd[dest]



#assert shortest(19) == 19
#assert shortest(23) == 15
#assert shortest(1) ==1

shortest(10**6)


for tc in range(1, 1 + int(sys.stdin.readline())):
    N  = int(sys.stdin.readline().strip())


    #res = "%d" % shortest(N)
    res = "%d" % costd[N]
    print "Case #%d: %s" % (tc, res)



