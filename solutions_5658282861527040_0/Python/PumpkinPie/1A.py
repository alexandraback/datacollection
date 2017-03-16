from __future__ import division

import os
import os.path, time
import itertools



'''fo=open("A-large.in")
fw=open("A-large.txt","w")'''
fo=open("B-small-attempt0.in")
fw=open("B-small-attempt0.txt","w")
'''fo=open("test.txt")
fw=open("testout.txt","w")'''
c=int(fo.readline())
for p in range(0,c):
       
        n=fo.readline()
        A=int(n.split()[0])
        B=int(n.split()[1])
        K=int(n.split()[2])
        count=0
        for i in range(0,A):
                for j in range(0,B):
                        if i&j<K:
                                count=count+1
        print count
                        
        
        
        
               
        
        fw.write("Case #"+ str(p+1)+": "+str(count)+"\n")
                      
               
fw.close()

        
                





