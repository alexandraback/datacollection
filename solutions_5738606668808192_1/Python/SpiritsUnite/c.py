from random import *
seed(1337)

con = [0]*1000000
con[0] = 1
con[1] = 1
primes = []
for i in xrange(2, 1000000):
    if con[i]: continue
    primes += [i]
    for j in xrange(i + i, 1000000, i):
        con[j] = 1

T = int(raw_input())
n, j = map(int, raw_input().strip().split())
print "Case #1:"
ans = set()
while len(ans) != j:
    s = "1" + ''.join(str(randint(0, 1)) for i in xrange(n-2)) + "1"
    t = int(s)
    if t in ans: continue
    l = []
    for i in xrange(2, 11):
        x = int(s, i)
        f = False
        for p in primes:
            if p >= x: break
            if x % p == 0:
                l += [p]
                f = True
                break
        if not f: break
    if len(l) == 9:
        ans.add(t)
        print s, ' '.join(map(str, l))

