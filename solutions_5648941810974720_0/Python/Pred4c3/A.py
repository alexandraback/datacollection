import sys
from copy import copy

let = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def conv(w):
    d = {}
    for c in w:
        d[c] = d.get(c,0)+1
    return d

letd = [conv(w) for w in let]

def can_fit(d1,d2):
    for k,v in d2.items():
        if k not in d1 or d1[k]<v:
            return False
    return True

def remove(d1,d2):
    d1 = copy(d1)
    for k,v in d2.items():
        d1[k]-=v
    return d1

T=int(input())
for case_id in range(1,T+1):
    S=input()
    def solve():
        def rec(i, rem, res):
            if i == 10:
                return res if all(x==0 for x in rem.values()) else None
            if can_fit(rem, letd[i]):
                rem2 = remove(rem,letd[i])
                res2 = copy(res)
                res2[i]+=1
                a = rec(i,rem2,res2)
                if a != None:
                    return a
            return rec(i+1,rem,res)

        p = [0]*10
        s = conv(S)
        res = rec(0,s,p)
        return ''.join(str(i)*res[i] for i in range(10))

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
