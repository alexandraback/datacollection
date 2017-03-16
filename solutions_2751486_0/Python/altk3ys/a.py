from itertools import *

def cc(s,n):
    l = 0
    for c in s:
        if c in 'aeiou':
            l=0
        else:
            l+=1
        if l >= n: return True
    return False

def solve(w,n):
    return sum(1 for i,j in combinations(range(len(w)+1),2)
               if cc(w[i:j],n))

rd=raw_input
for t in range(1,1+int(rd())):
    w, n = rd().split()
    print 'Case #%d: %d' % (t, solve(w, int(n)))
