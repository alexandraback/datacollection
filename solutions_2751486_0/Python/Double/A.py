#!/usr/bin/env python
import math
T=int(raw_input().strip())

yuanyin=['a','e', 'i', 'o', 'u']
for i in range(1, T+1):
    s, n = raw_input().strip().split()
    n=int(n)
    l=len(s)
    total=0
    d={}
    for j in range(0, l):
        ok=True
        for k in range(0, n):
            if j+k>=l:
                ok=False
                break
            if s[j+k] in yuanyin:
                ok=False
                break

        if ok:
            #total+=(j+1)*(l-(j+k))-1
            for b in range(0, j+1):
                for a in range(0, l-(j+k)):
                    ns='%d%s%d' % (b, s[b:j+k+a+1], j+k+a)
                    #print ns
                    if ns in d:
                        continue
                    else:
                        total+=1
                        d[ns]=True
    #total+=1

    print 'Case #%d: %d' % (i, total)

