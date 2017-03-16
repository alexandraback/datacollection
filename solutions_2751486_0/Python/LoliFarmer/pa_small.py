#!/usr/bin/python


import sys
def chk(inp):
    LL = len(inp)
    cnt = 0
    mx = 0
    for j in xrange(LL):
        if inp[j]!='a' and inp[j]!='e' and inp[j]!='i' and inp[j]!='o' and inp[j]!='u':
            cnt+=1
            if cnt > mx:
                mx = cnt
        else:
            cnt = 0
    return mx



T = int( raw_input() )
for f in xrange(1, T+1):
    [s, p] = raw_input().split()
    p = int(p)
    
    visit = {}
    L = len(s)
    ans = 0
    for i in xrange(0,L):
        for j in xrange(i+p,L+1):
            ss = s[i:j]
#            if ss in visit:
#                continue
#            visit[ss] = 1
            if chk(ss) >= p:
                ans+=1

    print 'Case #' + str(f) +': ' + str(ans) 



 
