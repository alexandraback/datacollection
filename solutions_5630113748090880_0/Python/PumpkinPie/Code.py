from __future__ import division

import os
import os.path, time
import itertools
import numpy as np



#fo=open("test.txt")
#fw=open("test_out.txt","w")
fo=open("B-small-attempt0.in")
fw=open("B-small-attempt0.out","w")
#fo=open("A-large.in")
#fw=open("A-large.out","w")
a=0

def missing(Listof):
        howmany=[[x,Listof.count(x)] for x in set(Listof)]
        missarr=[]
        for i in range(0,len(howmany)):
                if howmany[i][1]%2==1:
                        missarr.append(howmany[i][0])
        missarr= sorted(missarr)
        missstr=' '.join(str(e) for e in missarr)             
                        
        return(missstr)
        

n=int(fo.readline())
for k in range(0,n):
        Line=fo.readline().split()
        N=int(Line[0])
        Matrix=[]
        Listof=[]
        for i in range(0,2*N-1):
                Probline=fo.readline().strip("\n")
                Prob=[int(i) for i in Probline.split(" ")]
                Matrix=Matrix+[Prob]
                Listof=Listof+Prob

        missstr=missing(Listof)
        print missstr
        print "Case #"+ str(k+1)+": "
        fw.write("Case #"+ str(k+1)+": ")
        fw.write(str(missstr)+"\n")         
fw.close()        
        
                





