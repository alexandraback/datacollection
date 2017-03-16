from __future__ import division

import os
import os.path, time
import itertools
import numpy as np



#fo=open("test.txt")
#fw=open("test_out.txt","w")
fo=open("C-small-attempt1.in")
fw=open("C-small-attempt1.out","w")
#fo=open("A-large.in")
#fw=open("A-large.out","w")
a=0

def findrep(BFF,cir):
        arr=[i for i in range(0,len(BFF))]
        diff=list(set(arr)-set(cir))
        #print "diff=",diff
        good=-1
        for i in range(0,len(diff)):
                if BFF[diff[i]]==cir[0]:
                        good=diff[i]
        for i in range(0,len(diff)):
                if BFF[diff[i]]==cir[-1]:
                        good=diff[i]
        return good
        

def BFFcir(BFF):
        lenc=0
        for j in range(0,len(BFF)):
                i=j
                cir=[j]
                while len(cir)<len(BFF):
                        if (BFF[i] in cir) :
                                if(BFF[i]!=cir[-2]):
                                        break
                                elif BFF[i]==cir[-2]:
                                        #print"already"
                                        good=findrep(BFF,cir)
                                       
                                        if good!=-1:
                                                
                                                cir.append(good)
                                                i=BFF[good]
                                                #print i
                                        break
                                
                        else:
                                cir.append(BFF[i])
                                i=BFF[i]
                        

                cir=np.array(cir)+1
                print cir
                if len(cir)>lenc:
                        lenc=len(cir)
        return(lenc)

n=int(fo.readline())
for k in range(0,n):
        print "Case #"+ str(k+1)+": "
        Line=fo.readline().split()
        Kids=int(Line[0])
        Line=fo.readline().strip("\n")
        BFF1=[int(i) for i in Line.split(" ")]
        BFF=np.array(BFF1)-1
        BFF=list(BFF)
        
        print BFF1
        lenc=BFFcir(BFF)
        print lenc
        
        fw.write("Case #"+ str(k+1)+": ")
        fw.write(str(lenc)+"\n")         
fw.close()        
        
                





