#!/usr/bin/env python

import sys

import string

infile=open(sys.argv[1])

def solve(N,ab_s):
    assert len(ab_s)==N
    
    ab_s=sorted(ab_s,key=lambda x:x[1])
    #print ab_s

    star=0
    ans=0
    while ab_s:
        if ab_s[0][1]<=star:
            if ab_s[0][0]==9999:
                star+=1
            else:
                star+=2
            del ab_s[0]
            ans+=1
        else:
            cands=[n for n in range(len(ab_s)) if ab_s[n][0]<=star]
            if len(cands)==0:
                return "Too Bad"
            else:
                d=max( cands, key=lambda x: ab_s[x][1] )
                ab_s[d][0]=9999
                star+=1
                ans+=1
        #print ab_s,star
    return str(ans)
    

head=True
Q=0
for n,line in enumerate(infile):
    if n==0:
        T=int(line)
        continue
    elif head:
        N=int(line)
        head=False
        ab=[]
        Q+=1
    else:
        a,b=line.split()
        ab.append([int(a),int(b)])
        if len(ab)==N:
            ans=solve(N,ab)
            head=True
            print "Case #%d: %s" % (Q,ans)

