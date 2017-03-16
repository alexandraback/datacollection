from itertools import izip
from collections import Counter



def CASE(IN):
    def rstr(): return IN.readline().strip()
    def rint(): return int(rstr())
    def rints(): return map(int, rstr().split())
    def nrints(N): return [rints() for i in xrange(N)]
    
    K, N = rints()
    keys = rints()
    C = []
    CK = []
    for row in nrints(N):
        C.append(row[0])
        CK.append(row[2:])

    W = set()
    global counter
    counter = 0
    def find_next(UN, keys):
        #global counter
        #counter += 1
        if not UN:
            return []
        if UN in W:
            return None

        for u in sorted(UN):
            k = C[u]
            if keys[k] == 0:
                continue
            keys[k] -= 1
            keys.update(CK[u])
            res = find_next(UN.difference([u]), keys)
            if res is None:
                keys[k] += 1
                keys.subtract(CK[u])
                continue
            res.append(u)
            return res
        W.add(UN)
        return None
    try:
        res = find_next(frozenset(xrange(N)), Counter(keys))
    except KeyboardInterrupt:
        #print "counter : ", counter
        sys.exit()
    #print "counter : ", counter

    if res is None:
        return "IMPOSSIBLE"
    return ' '.join(map(lambda x: str(x+1), reversed(res)))

def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1,t+1):
        #print "test %i" % i
        OUT.write("Case #%i: %s\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
