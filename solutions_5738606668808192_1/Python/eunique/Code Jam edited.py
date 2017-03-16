import math
output = open("outputlarge.txt","w")
def isPrime(n):
    if n == 1:
        return False
    else:
        for i in range(2,n):
            if n%i==0:
                return False
        return True

def factor(n):

    for i in range(2,500):
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


alist=[]
for i in range(0,2**31):
    if len(alist)<500:
        newnum = 2*i+1+2**31
        finalbin=int(bin(newnum)[2::])
        if "Prime" not in represent(finalbin):
            alist.append(represent(finalbin))
    else:
        break

output.write("Case #1: \n")
for element in alist:
    output.write(element+"\n")
    
output.close()
