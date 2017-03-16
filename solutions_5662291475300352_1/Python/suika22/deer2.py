#import numpy as np

myinf = "sample.txt"
myinf = "C-small-2-attempt0.in"
#myinf = "B-large-practice.in"

myout = open("output.txt",'wt')
#myout = open("output1.txt",'wt')
#myout = open("output2.txt",'wt')

#import sys
#sys.setrecursionlimit(2000)

myin = open(myinf,'rt').read().split('\n')
num_case = int(myin[0])
print(num_case)

cnt_i=1
for i in range(num_case): 
    N=int(myin[cnt_i])
    coor=[]
    for j in range(1,N+1):
        coor += [[int(x) for x in myin[cnt_i+j].split()]]
    cnt_i+=N+1
    #print(N,coor)
    s=[x[2] for x in coor]
    ms = min(s)
    mi = s.index(ms)
    a=ms*(360-coor[mi][0])/360
    b=ms*(360-coor[mi][0])/360+ms
    y=0
    for c in coor:
        x=c[2]*(360-c[0])/360
        if c[2]!=ms and b<=x:
            y+=1

    print(y)
    myout.write("Case #%d: %s\n"%((i+1),y))

myout.close()    
