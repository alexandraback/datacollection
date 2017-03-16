from math import sqrt

file = open('C-large.in', 'r')
file2 = open('C-large.out', 'w')

nbCase=int(file.readline())

def isDivided(x):
    for i in range(2,int(sqrt(x))+1):
        if x%i==0:
            return(i)
    return(0)


def isCoinJam(s):
    t=[0]*9
    for b in range(2,11):
        x=0
        for l in s:
            x*=b
            x+=int(l)
        temp=isDivided(x)
        t[b-2]=isDivided(x)
        if temp==0:
            return(t)
    return(t)

for i in range(nbCase):
    file2.write("Case #"+str(i+1)+":\n")
    n,j=[int(i) for i in (file.readline().split())]
    seed=0

    while j:

        b=bin(seed)[2:]
        b="1"+"0"*(n-len(b)-2)+b+"1"
        #print(b)
        result=isCoinJam(b)
        #print(result)
        if 0 not in result:
            file2.write(str(b)+" "+" ".join([str(i)for i in result])+"\n")
            j-=1
        seed+=1
