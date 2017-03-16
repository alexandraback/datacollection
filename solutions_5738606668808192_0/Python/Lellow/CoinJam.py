import math as math

fichierR = open("C-small.in","r")
fichierW = open("C-small.out","w+")

def convert(n,b):
    s=0
    i=0
    while(n!=0):
        s+=(n%10)*b**i
        n=n//10
        i+=1
    return s

def findDiv(n):
    for i in range(2,int(math.sqrt(n))+1):
        if (n%i == 0):
            return i
    return -1

def convBin(n):
    s=0
    i=0
    while(n!=0):
        if(n%2!=0):
            s+=10**i
        i+=1
        n=n//2
    return s


def CoinJam(n):
    tab=[]
    for i in range(1,10):
        k=convert(n,i+1)
        j=findDiv(k)
        if(j!=-1):
            tab.append(j)
        else:
            return -1
    return tab

def CoinJams(n,k):
    min=2**(n-1)
    max=2*min
    for i in range(min,max):
        if(k==0):
            return
        else:
            if (i%2!=0):
                a = CoinJam(convBin(i))
                if (a!=-1):
                    print(k)
                    k-=1
                    fichierW.write(str(convBin(i)))
                    for j in range(0,9):
                        fichierW.write(" ")
                        fichierW.write(str(a[j]))
                    fichierW.write("\n")

def allBin(fichierR):
    a = (fichierR.readline()).split()
    n = int(a[0])
    k = int(a[1])
    fichierW.write("CASE #")
    fichierW.write("1")
    fichierW.write(":")
    fichierW.write("\n")
    CoinJams(n,k)

print(CoinJam(100011))

fichierR.readline()
allBin(fichierR)