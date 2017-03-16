import numpy as np

prime = dict()

fullLst = np.arange(2**16)
curr=2
while curr*curr<len(fullLst):
    if fullLst[curr]!=curr:
        fullLst[curr]=1
    else:
        for j in range(curr*curr, len(fullLst), curr):
            while fullLst[j]%curr==0:
                fullLst[j]=fullLst[j]/curr
    curr=curr+1
allPrimes = [e for e,ele in enumerate(fullLst) if ele>1]



def isPrime(x):
    for curr in allPrimes:
        if x>curr and x%curr==0:
            return curr
    return 0

def check(n):
    lst=[]
    for base in range(2, 11):
        curr = 0
        for i in range(len(n)):
            curr=curr*base+int(n[i])
        if prime.has_key(curr):
            if prime[curr]==0:
                return []
        else:
            prime[curr]=isPrime(curr)
            if prime[curr]==0:
                return []
        lst.append(prime[curr])
    return lst
    
def fillCurr(curr):
    c=curr
    s=''
    while c>0:
       s=s+str(c%2)
       c=c/2
    return '1'+s[::-1].zfill(14)+'1'
    


lst=[]
curr=0
while len(lst)<50:
    ss = fillCurr(curr)
    currLst = check(ss)
    if len(currLst)==9:
        lst.append([ss,currLst])
    curr=curr+1

print "Case #1:"
for ele in lst:
    print ele[0],
    for e in ele[1]:
        print e,
    print
