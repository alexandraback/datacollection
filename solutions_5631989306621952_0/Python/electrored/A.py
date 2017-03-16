import sys
from collections import deque as dq

rd = open("A-small-attempt0.in","r")
wrt = open("A.out", "w")

def solve(s):
    ls = list(s[1:])
    ans = dq()
    ans.append(s[0])
    ln = len(ls)
    for i in xrange(ln):
        if ord(ls[i]) >= ord(ans[0]):
            ans.appendleft(ls[i])
        else:
            ans.append(ls[i])
    ans = "".join(str(i) for i in ans)
    return ans

for test in xrange(1, int(rd.readline()) + 1):
    s = rd.readline()
    ans1 = solve(s)
    ans = "Case #%d: %s" %(test, ans1)
    wrt.write(ans)
    
wrt.close()
