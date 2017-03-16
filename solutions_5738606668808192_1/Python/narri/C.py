import sys
import random

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

PLIM = 2**21
parr = [True for i in xrange(PLIM)]
parr[0] = parr[1] = False
for i in xrange(4,PLIM,2):
    parr[i] = False

primes = [2]
for i in xrange(3,PLIM,2):
    if not parr[i]:
        continue
    primes.append(i)
    for j in range(i*i, PLIM, i):
        parr[j] = False

print >>sys.stderr, "DONE PRIMES", len(primes)

sprimes = set(primes)

def isp(x):
    if x in sprimes:
        return True
    for p in primes:
        if p * p > x:
            return True
        if x % p == 0:
            return p
    return True

def check(arr):
    out = []
    for base in xrange(2, 11):
        n = 0
        for t in arr:
            n *= base
            n += t
        tt = isp(n)
        if tt is True:
            return None
        out.append(tt)
    return out

def solve(N, J):
    out = []
    se = set()
    while len(out) < J:
        myrand = [1] + [random.randint(0,1) for i in xrange(N-2)] + [1]
        arr = check(myrand)
        if arr is not None:
            mystr = ''.join(str(x) for x in myrand) 
            if mystr in se:
                continue
            out.append([mystr] + arr)
            print >>sys.stderr, "GOT", len(out), out[-1]
    return out

T = int(cin())
for cn in xrange(1,T+1):
    n, j = int(cin()), int(cin())
    #print "Case #%d: %s" % (cn, str(solve(s)))
    answers = solve(n,j)
    print 'Case #%d:' % (cn,)
    for ans in answers:
        print ' '.join(str(x) for x in ans)




