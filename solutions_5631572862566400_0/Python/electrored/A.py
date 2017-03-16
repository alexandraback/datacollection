import sys
from collections import deque as dq

rd = open("C-small-attempt0.in","r")
wrt = open("A.out", "w")

def fun1(ar):
    s = set()
    for i in xrange(1,n+1):
        if ar[ar[i]] == i and i not in s and ar[i] not in s:
            s.add(i)
            s.add(ar[i])
    return s

def fun2():
    ans = 0
    for i in xrange(1,n+1):
        tmp = 0
        ii = i
        while tmp < n and ar[ii] != i:
            ii = ar[ii]
            tmp += 1
        ans = max(ans, tmp)
    return ans

def fun3(ar):
    s = fun1(ar)
    ans = 0
    for i in xrange(1,n+1):
        ls = [i]
        for j in xrange(n):
            if ar[ls[-1]] in ls:
                break
            ls.append(ar[ls[-1]])
        if ar[ls[-1]] != ls[0] and ar[ls[-1]] != ls[-2]:
            continue
        
        for j in xrange(1,n+1):
            if j not in s and j not in ls and ar[ls[-1]] == ls[-2]:
                if ar[j] == ls[-1]:
                    ls.append(j)
                    break
        
        for j in xrange(1,n+1):
            if j in s and j not in ls:
                if ar[j] in s and ar[j] not in ls:
                    ls.append(j)
                    ls.append(ar[j])
            for k in xrange(1,n+1):
                if k not in s and k not in ls and ar[ls[-1]] == ls[-2]:
                    if ar[k] == ls[-1]:
                        ls.append(k)
                        break
        
        for j in xrange(1,n+1):
            if j not in ls and ar[ls[-1]] == ls[-2]:
                if ar[j] == ls[0]:
                    ls.append(j)
        if len(ls) > ans:
            ans = len(ls)
    return ans

for test in xrange(1, int(rd.readline()) + 1):
    n = int(rd.readline())
    seq = range(1,n+1)
    ar = map(int,rd.readline().split())
    ar = [0] + ar
    ans1 = fun3(ar)
    ans = "Case #%d: %s\n" %(test, ans1)
    wrt.write(ans)
    
wrt.close()
