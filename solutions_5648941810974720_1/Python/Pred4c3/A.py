import sys
from copy import copy

let = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def conv(w):
    d = {}
    for c in w:
        d[c] = d.get(c,0)+1
    return d

letd = [conv(w) for w in let]

def remove(d1,d2):
    d1 = copy(d1)
    for k,v in d2.items():
        d1[k]-=v
    return d1

T=int(input())
for case_id in range(1,T+1):
    S=input()
    def solve():
        p = [0]*10
        s = conv(S)
        uq = ((0,'Z'),(2,'W'),(4,'U'),(6,'X'),(8,'G'),(3,'H'),(7,'S'),(5,'V'),(9,'I'),(1,'O'))
        for idx,c in uq:
            for i in range(s.get(c,0)):
                p[idx] += 1
                s = remove(s,letd[idx])
        return ''.join(str(i)*p[i] for i in range(10))

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
