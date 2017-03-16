#!/usr/bin/env python
#
# Problem: 
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


V = list('aeiou')

for case in range(int(raw_input())):
    s, n = raw_input().split()
    n = int(n)
#    = map(int, raw_input().split())
    l = len(s)
    c = 0
    for i in range(l-n+1):
        for j in range(i+n, l+1):
            cc = 0
            p = 0
            for k in s[i:j]:
                if p == 0 and k not in V:
                    p = 1
                    cc += 1
                elif p == 1 and k not in V:
                    cc += 1
                elif p == 1 and k in V:
                    p = 0
                    cc = 0
                else:
                    cc = 0
                if cc >= n:
                    c += 1
#                    print s[i:j]
                    break


#            print s[i:j]

        
    ans = c
    print "Case #%d: %s" % (case+1, ans)
