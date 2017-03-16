import sys
from fractions import gcd
r = lambda: sys.stdin.readline()

t = int(r())

def log2(a):
    if a == 1:
        return 0
    if a % 2 == 1:
        return -1
    answer = log2(a/2)
    if answer == -1:
        return -1
    return answer+1

for ti in xrange(1, t+1):
    p, q = map(int, r().split('/'))
    g = gcd(p, q)
    p /= g
    q /= g
    l2 = log2(q)
    if l2 == -1:
        print "Case #"+str(ti)+": impossible"
    else:
        answer = 1
        while p * 2 < q:
            answer += 1
            p *= 2
        print "Case #"+str(ti)+": "+str(answer)
