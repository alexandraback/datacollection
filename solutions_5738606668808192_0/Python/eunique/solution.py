










import time
def isPrime(n):
    if n == 1:
        return False
    else:
        for i in range(2,n):
            if n%i==0:
                return False
        return True

def factor(n):
    if isPrime(n)==False:
        for i in range(2,n):
            if n%i==0:
                return i
                break
    else:
        return "Prime"
    

def convert(binarystring, base):
    value = 0
    for index in range(0, len(str(binarystring))):
        value+=(int(str(binarystring)[index])*(base**(len(str(binarystring))-1-index)))
    return value    

def isjamcoin(binarystring):
    for base in range(2,11):
        newvalue=convert(binarystring,base)
        if isPrime(newvalue):
             return False
    return True


def represent(binarystring):
    reprstring=str(binarystring)
    for base in range(2,11):
        newvalue=convert(binarystring,base)
        reprstring+=" "+str(factor(newvalue))
    return reprstring

"""def calculateall(n,j):
    alist=[]
    onestring="1"

    for i in range(0,2**(n-2)):
        if len(alist)<j:
            substring = str(bin(i))[2::]
            if len(substring)!=n-2:
                modstring=""
                for a in range(1,n-2-len(substring)+1):
                    modstring+="0"
                finalbin = int(onestring+modstring+substring+onestring)
            else:
                finalbin = int(onestring+substring+onestring)

            if isjamcoin(finalbin):
                alist.append(represent(finalbin))
        else:
            break
    return alist

alist=[]

def a(i):
    newnum = 2*i+1+2**15
    finalbin=(bin(newnum)[2::])
    return (represent(finalbin))

for i in range(15,16):
    if len(alist)<50:
        newnum = 2*i+1+2**15
        finalbin=int(bin(newnum)[2::])
        if isjamcoin(finalbin):
            alist.append(represent(finalbin))
    else:
        break"""

#print (alist)
    

