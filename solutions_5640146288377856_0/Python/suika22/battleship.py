#import numpy as np
from math import ceil

myinf = "sample.txt"
myinf = "A-small-attempt0.in"
#myinf = "B-large-practice.in"

myout = open("output.txt",'wt')
#myout = open("output1.txt",'wt')
#myout = open("output2.txt",'wt')

#import sys
#sys.setrecursionlimit(2000)

myin = open(myinf,'rt').read().split('\n')
num_case = int(myin[0])
print(num_case)
for case_i in range(num_case):
 
    shift=case_i+1
    #N = int(myin[shift]) #for single input
    inputs = myin[shift].split()
    in_ints = [int(x) for x in inputs]  #for ints
    #in_floats = [float(x) for x in inputs] #fot floats
    R=in_ints[0]
    C=in_ints[1]
    W=in_ints[2] 

    y = ceil(C/W)+(W-1)

    #y='output'
    print(case_i,y)
    myout.write("Case #%d: %d\n"%((case_i+1),y))

myout.close()    
