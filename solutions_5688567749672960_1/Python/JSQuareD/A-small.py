import math

def IsFlippable(n):
    return (str(n)[-1] != '0' and Flip(n) < n)
    
def Flip(n):
    return int(str(n)[-1::-1])
    
def alternative(n):
    ans = 0
    while(True):
        k = math.floor(math.log10(n))
        if k == 0:
            ans += n
            break
        
        K = 10**k
        leading = math.floor(n/K)
        m = math.ceil((k+1)/2)
        
        tail = int(str(n)[-m:])
        if tail == 0:
            ans += 1
            n -= 1
            continue
        
        ans += tail-1
        n -= tail-1
        
        if Flip(n) < n:
            ans+=1
            n = Flip(n)
        else:
            ans += 2
            n -= 2
    return ans
    
"""
A = [-1] * 1000100
A[1] = 1
for n in range(2,len(A)):
    A[n] = A[n-1] + 1
    if IsFlippable(n):
        A[n] = min(A[n], A[Flip(n)]+1)
   
 
def getSequence(n):
    if n == 1:
        return [1]
    if IsFlippable(n) and A[Flip(n)] < A[n-1]:
        l = getSequence(Flip(n))
    else:
        l = getSequence(n-1)
    l.append(n)
    return l
"""
    
def getSequence(n):
    l = [n]
    while(True):
        if n == 1:
            break
        if IsFlippable(n) and A[Flip(n)] < A[n-1]:
            l.append(n)
            n = Flip(n)
            l.append(n)
        else:
            n = n-1
    return l
        
T = int(input())
for t in range(1,T+1):
    N = int(input())
    print("Case #%i: %i" % (t, alternative(N)))