#!/usr/bin/python

from collections import deque

def ir():
    return int(raw_input())

def ia():
    line = raw_input()
    line = line.split()
    return map(int, line)

def sa():
    line = raw_input()
    line = line.split()
    return line

def G(n):
    l = [False]*n
    while True:
        for i, v in enumerate(l):
            if not v:
                l[i] = True
                break
            else:
                l[i] = False
                continue
        else:
            yield l
            return
        yield l

def good(DD):
    s1 = set()
    s2 = set()
    for f, w1, w2 in DD:
        if f == False:
           s1.add(w1); s2.add(w2)
        elif f == True:
            if not (w1 in s1):
                return False
            if not (w2 in s2):
                return False
    return True

def solve():
    n = ir()
    D  = [ ]
    for i in range(n):
        w1, w2 = sa()
        D.append( (w1, w2) )
    n = len(D)
    
    ans = 0
    for l in G(n):
        nfake = sum(l)
        if nfake<=ans: continue
        DD = [(f, w1, w2) for f, (w1, w2) in zip(l, D)]
        DD.sort()
        if good(DD):
            ans = nfake
    return ans

T = ir()
for i in range(T):
    ans = solve()
    print 'Case #%d: %s' % (i+1, ans)

# a, b  -       -
#       |       |
# c, d  |  -  - |
#       |  |  | |
# a, d  -  -  | |
#             | |
# c, b        - -
