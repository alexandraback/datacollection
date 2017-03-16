#!/usr/bin/python -SOO
import re
for case in range(1,int(input())+1):
    s,n = input().strip().split()
    n = int(n)
    r = re.compile('[^aeiou]{%d}'%n)
    t,prev = 0,-1
    cs = [int(i not in 'aeiou') for i in s]
    for i in range(1,len(s)):
        if cs[i]: cs[i]+=cs[i-1]
    for i in range(len(s)-n+1):
        if cs[i+n-1]>=n:
            t+=(i-prev)*(len(s)-i-n+1)
            prev=i
    print('Case #{}: {}'.format(case,t))
