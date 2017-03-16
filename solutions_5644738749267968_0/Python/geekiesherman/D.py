from sys import stdin

def r():
    return next(stdin)

def nice(n, k):
 n = n[:]; k = k[:]; pts = 0
 for x in xrange(len(n)):
   ch = n.pop(-1)
   if k[-1] < ch:
     k.pop(0)
     pts+=1
   else:
     k.pop(k.index(min(b for b in k if b > ch)))
 return pts


def deceit(n, k):
 n = n[:]; k = k[:]; pts = 0
 for x in xrange(len(n)):
   canwin = max(n) > max(k)
   if canwin:
     n.pop(n.index(min(b for b in n if b > k[-1])))
     k.pop(-1)
     pts+=1
   else:
     k.pop(-1)
     n.pop(0)
 return pts


T = int(r())
for t in xrange(1,T+1):
    r()
    N = sorted(map(float, r().split(" ")))
    K = sorted(map(float, r().split(" ")))
    print "Case #{}: {} {}".format(t, deceit(N, K), nice(N, K))
