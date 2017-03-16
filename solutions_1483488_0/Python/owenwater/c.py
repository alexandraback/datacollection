#!/usr/bin/python

import sys
import math

num = 3001

list=[0] * num

if __name__=="__main__":
    for i in range(0,num):
        if i % 100000 == 0:
            sys.stderr.write(str(i *1.0/num * 100)+"\n")
        tmp = []
        s = str(i)
        h = set()
        for j in range(1,len(s)):
            v = int(s[j:]+s[:j])
            if v > i and v not in h:
                tmp.append(v)
                h.add(v)
        tmp.sort()
        list[i] = tmp
    sys.stderr.write("Init Done.\n")
    
    data = sys.stdin.readlines()
    N = int(data[0].strip())
    for id,line in enumerate(data[1:]):
        digits = line.strip().split(' ')
        a,b = int(digits[0]) , int(digits[1])
        res = 0
        for i in range(a,b+1):
            tmp = list[i]
            if len(tmp) == 0:
                continue
            be = 0; en = len(tmp)-1
            ans = -1
            while be <= en:
                m  = (be+en)/2
                if tmp[m] <= b:
                    ans = max(ans,m)
                    be = m + 1
                elif tmp[m] > b:
                    en = m - 1
            res += ans + 1
        #sys.stderr.write(str(id*1.0/N*100)+"\n")
        print "Case #%d: %d" %(id+1, res)

    #sys.stderr.write("All Done.\n")

    #print list[1234]
    #print list[343251]
    #print list[1230]
    #print list[12304]
    #print list[10234]
    

