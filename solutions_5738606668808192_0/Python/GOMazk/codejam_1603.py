import sys

def chknotPrime(num):
    if num>1:
        for i in range(2, round(num**(0.5))):
            if ( num%i ==0):
                return i
        return 0
    else:
        return -1

caseN=int(input())
for i in range(1,caseN+1):
    dig, num=map(int,sys.stdin.readline().split())
    print("Case #%d:"%(i))
    for k in range(0,2**(dig-2)):
        if(num<=0):
            break
        jamcoin="1"
        for z in range(0,dig-2):
            jamcoin+="%d"%( (k//2**z)%2 )
        jamcoin+="1"

        evid=list()
        isjam=1
        for base in range(2,11):
            test=0
            for z in range(0,dig):
                test+=int(jamcoin[-z-1])*(base**z)
            dv=chknotPrime(test)
            if (dv>0):
                evid.append(dv)
            else:
                isjam=0
                break
        if(isjam):
            print(jamcoin,evid[0],evid[1],evid[2],evid[3],evid[4],evid[5],evid[6],evid[7],evid[8])
            num-=1
