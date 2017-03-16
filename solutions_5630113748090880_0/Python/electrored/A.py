import sys
from collections import deque as dq

rd = open("B-small-attempt0.in","r")
wrt = open("A.out", "w")

def solve():
    d = {}
    for i in xrange(2*n - 1):
        for j in xrange(n):
            tmp = ar[i][j]
            if tmp not in d:
                d[tmp] = 0
            d[tmp] += 1
    ls = []
    for i in d:
        if d[i]%2 == 1:
            ls.append(i)
    ls.sort()
    ls = " ".join(str(i) for i in ls)
    return ls

for test in xrange(1, int(rd.readline()) + 1):
    n = int(rd.readline())
    ar = [map(int,rd.readline().split()) for i in xrange(2*n - 1)]
    ans1 = solve()
    ans = "Case #%d: %s\n" %(test, ans1)
    wrt.write(ans)
    
wrt.close()
