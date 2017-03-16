# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 13:25:51 2016

@author: David
"""
import math
def form(nums,k):
    #print nums
    val = nums[0]
    for n in nums[1:]:
        val = (val-1)*k + n
    return val
fin = open("file.in","r")
fout = open("file.out","w")
i = int(fin.readline())
for l in range(i):
    k,c,s = map(int,fin.readline().split())
    checks = []
    #print math.ceil(k/float(c)),k,c
    if s < math.ceil(k/float(c)):
        fout.write("Case #%d: IMPOSSIBLE"%(l+1)+"\n")
        continue
    for j in range(int(math.ceil(k/float(c)))):
        if (c > k):
            checks.append(form([1 for x in range(c-k)] + range(1,k+1),k))
            continue
        val = 0
        if (j+1)*c > k:
            val = form(range(k-c+1,k+1),k)
        else:
            val = form(range(j*c+1,(j+1)*c+1),k)
        #print val
        checks.append(val)
    fout.write("Case #%d: "%(l+1)+' '.join(map(str,checks))+"\n")
    
    
    
fin.close()
fout.close()