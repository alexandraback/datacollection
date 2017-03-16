from math import *
def find(S,x,L,R):
    while R-L>1:
        mid =(L+R)//2
        #print([L,R,mid])
        if S[mid]<x:
            R=mid
        else:
            L=mid
    return L
    

f = open("B-small-attempt0.in",'r')
#f = open("B-large.in",'r')
#f=open("B-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    f.readline()
    S=[int(j) for j in str.split(f.readline())]
    S.sort(reverse=True)
    S=S+[0]
    print(S)
    curmin = S[0]
    eatsec = S[0]
    goOn=True
    while goOn and eatsec>1:
        eatsec +=-1
        k= (S[0]-1)//eatsec
        ssec = 0
        for j in range(1,k+1):
            ssec += 1+find(S,eatsec*j+1,0,len(S)-1)
            #print(ssec)
        #print([eatsec,ssec,eatsec+ssec,curmin])
        if ssec >curmin:
            goOn =False
        if ssec+eatsec<curmin:
            curmin =ssec+eatsec
    output.write("Case #"+str(case)+": "+str(curmin)+"\n")
    
output.close()
f.close()
