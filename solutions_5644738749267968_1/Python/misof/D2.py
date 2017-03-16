T = int( input() )

def solvewar(A):
    answer, avail = 0, 0
    for x in A:
        if x==0: avail+=1
        elif avail>0: answer, avail = answer+1, avail-1
    return len(A)//2 - answer

for test in range(1,T+1):
    N = int( input() )
    Naomi = [ int( 10**7 * float(x) + 0.5 ) for x in input().split() ] + [ 10**9 ]
    Ken   = [ int( 10**7 * float(x) + 0.5 ) for x in input().split() ] + [ 10**9 ]
    A = []
    for n in range(2*N):
        if min(Naomi) < min(Ken):
            A.append(0)
            Naomi.remove( min(Naomi) )
        else:
            A.append(1)
            Ken.remove( min(Ken) )
    answer2 = solvewar(A)
    answer1 = answer2
    answer1 = max( answer1, len(A)//2 - solvewar([1-x for x in A]) )
    while len(A):
        i=0
        while A[i]==1: i+=1
        A = A[:i] + A[i+1:]
        i=len(A)-1
        while A[i]==0: i-=1
        A = A[:i] + A[i+1:]
        answer1 = max( answer1, len(A)//2 - solvewar([1-x for x in A]) )
    print('Case #{}: {} {}'.format(test,answer1,answer2))
