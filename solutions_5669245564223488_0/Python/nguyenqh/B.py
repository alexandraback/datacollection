import math

def factorial(N):
    n = 1
    f = 1
    q = 1000000007
    while n<=N:
        f = (f*n)%q
        n = n+1
    return f

def prod(a,b):
    q = 1000000007
    return ((a%q)*(b%q))%q
        
def isiso(s):
    c = s[0]
    for c1 in s:
        if c1!=c: return False
    return True

##inputFile = open('B-sample.in','r')
##outputFile = open('B-sample.ou','w')
inputFile = open('B-small-attempt0.in','r')
outputFile = open('B-small-attempt0.ou','w')
##inputFile = open('A-large-practice.in','r')
##outputFile = open('A-large-practice.ou','w')
numTest = int(inputFile.readline())
for testid in range(1,numTest+1):
    N = int(inputFile.readline())
    cars = [s for s in inputFile.readline().split()]
    print(N,cars)

    letters = ''
    for s in cars:
        for c in s:
            if not c in letters: letters = letters+c

    begin = {c:0 for c in letters}
    end   = {c:0 for c in letters}
    mid   = {c:0 for c in letters}
    iso   = {c:0 for c in letters}

    for s in cars:
        if isiso(s):
            iso[s[0]] = iso[s[0]]+1
        else:
            cb,ce = s[0],s[-1]
            begin[cb] = begin[cb]+1
            end[ce]   = end[ce] +1
            mid1  = {c:0 for c in letters}

            ks = 0
            while s[ks]==cb: ks=ks+1
            ke = len(s)-1
            while s[ke]==ce: ke=ke-1
            for c in s[ks:ke+1]:
                mid1[c]  = mid1[c]+1
            for c in mid1:
                if mid1[c]>0: mid[c] = mid[c]+1

    print(letters,begin,end,mid,iso)
    Niso = 0
    countZero = False
    for c in letters:
        if begin[c]>1 or end[c]>1 or mid[c]>1:
            countZero = True
            print('A')
            break            
        elif (mid[c]+begin[c])>1 or (mid[c]+end[c])>1 or (mid[c]>0 and iso[c]>0)>1:
            countZero = True
            print('B',c,mid[c]+begin[c],(mid[c]+end[c]),(mid[c]*iso[c]))
            break
        else:
            if begin[c]==1 and end[c]==1: N = N-1
            if begin[c]==0 and end[c]==0 and iso[c]>0: N = N+1
        Niso = Niso + iso[c]
    print(countZero)
    if countZero:
        print('Case #',testid,': ',0, sep='',file=outputFile)
    else:
        N1 = N-Niso
        print(N1,iso)
    ##    counts = [factorial(N1)]
        count = factorial(N1)
        for c in iso:
            if iso[c]>0:
                count = prod(count,factorial(iso[c]))
        print('Case #',testid,': ',count, sep='',file=outputFile)



outputFile.close()
    
        
