from __future__ import division

import os
import os.path, time
import itertools
import numpy as np



#fo=open("test.txt")
#fw=open("test_out.txt","w")
#fo=open("A-small-attempt0.in")
#fw=open("A-small-attempt0.out","w")
fo=open("A-large.in")
fw=open("A-large.out","w")
a=0

def win(Line):
        winn=[Line[0]]
        for i in range(1,len(Line)):
                if Line[i]>=winn[0]:
                        winn.insert(0,Line[i])
                else:
                        winn.insert(len(winn),Line[i])

        arr=[chr(i) for i in winn]
        str1=''.join(arr)
        return str1

n=int(fo.readline())
for k in range(0,n):
        #converts line to array of floats
        Probline=fo.readline().strip("\n")
        Line=[ord(i) for i in Probline]
        winn=win(Line)
        print winn
        print "Case #"+ str(k+1)+": "
        fw.write("Case #"+ str(k+1)+": ")
        fw.write(str(winn)+"\n")         
fw.close()        
        
                





