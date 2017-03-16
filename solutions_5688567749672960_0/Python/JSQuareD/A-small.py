def IsFlippable(n):
    return str(n)[-1] != '0'
    
def Flip(n):
    return int(str(n)[-1::-1])
    
A = [-1] * 1000100
A[1] = 1
for n in range(2,len(A)):
    A[n] = A[n-1] + 1
    if IsFlippable(n) and Flip(n) < n:
        A[n] = min(A[n], A[Flip(n)]+1)
        
T = int(input())
for t in range(1,T+1):
    N = int(input())
    print("Case #%i: %i" % (t, A[N]))