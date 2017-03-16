#import numpy as np

myinf = "sample.txt"
myinf = "C-small-1-attempt1.in"
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

    if N<=1:
        y=0
    elif coor[0][2]==coor[1][2] :
        y=0
    else:
        a=coor[0][2]*(360-coor[0][0])/360
        b=coor[1][2]*(360-coor[1][0])/360
        if a<=b:
            c=(a+coor[0][2]<=b)
        else:
            c=(b+coor[1][2]<=a)
        if c:
            y=1
        else:
            y=0
        #print(N,coor,y,a,b,a+coor[0][2],b+coor[1][2])
    print('f')
    myout.write("Case #%d: %s\n"%((i+1),y))

myout.close()    
