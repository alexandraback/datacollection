#p3
primes = [2,3,5,7,11,13,17,19,23]
N = 16
JOBS = 50

def factorize(N):
    for p in primes:
        if N%p==0: yield p

from itertools import product
LOOP = [[1]]
for _ in xrange(N-2): LOOP.append(range(2))
LOOP = LOOP + [[1]]

count = 0
for candidate in product(*LOOP):
    saw = []
    for base in xrange(2,11):
        num = sum( base**ix for ix,v in enumerate(candidate) if v )
        factors = set(factorize(num))
        if not factors:
            break
        else:
            saw.append(factors.pop())
    else:
        
        Z = "".join(map(str,candidate[::-1]))
        print Z," ".join(map(str,saw))
        assert( int( Z,2) % saw[0] == 0)
        count += 1
        if count == JOBS: break
        
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        S = rr()
        zetaans = solve(S)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
