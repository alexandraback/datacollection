from sys import stdin
from array import array


def recompose(n, l, min_v, max_v):
    if n<10: return 0
    base = 10**(l-1)
    c = n
    appear[c] = 1
    count = 1
    #print "begin: %d" % c
    for i in range(l-1):
       c = c%base*10 + c/base
       if c < base or c < min_v or c>max_v: continue
       if appear[c]: break
       appear[c] = 1
       if c < n:   return 0
       count = count+1
    return count*(count-1)/2 # C(n,2)

T = int(stdin.readline())
for t in range(1, T+1):
    (a,b) = stdin.readline().split(' ') 
    (a,b,l,c) = (int(a), int(b), len(str(a)), 0)
    appear = array('i', [0] * (2000000+1))
    for n in range(a,b+1):
        c += recompose(n, l, a, b)
    print "Case #%d: %d" % (t,c)
