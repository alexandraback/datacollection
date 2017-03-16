#!/usr/bin/python -SOO
import re
for case in range(1,int(input())+1):
    s,n = input().strip().split()
    n = int(n)
    r = re.compile('[^aeiou]{%d}'%n)
    t = 0
    for i in range(len(s)):
        for j in range(i+1,len(s)+1):
            if r.search(s[i:j]): t+=1
    print('Case #{}: {}'.format(case,t))
