from itertools import *

def solve(w,n):
    l = 0
    p = -1
    cc = []
    for i, c in enumerate(w+'a'):
        if c in 'aeiou':
            if l >= n:
                cc.append((p,p+l))
            l = 0
            p = -1
        else:
            if p == -1:
                p = i
            l+=1
    N = len(w)
    lo = 0
    res = 0
    for i,(l,h) in enumerate(cc):
        res += (1+l-lo) * (1+N - (l+n))
        for j in range(l,h-n):
            res += N-j-n
        lo = h-n+1
    return res

rd=raw_input
for t in range(1,1+int(rd())):
    w, n = rd().split()
    print 'Case #%d: %d' % (t, solve(w, int(n)))
