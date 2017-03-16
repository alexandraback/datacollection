t = int(input())
for i in range(t):
    n = int(input())
    A = [0]*2501
    for j in range(2*n-1):
        for x in map(int,input().split()):
            A[x] += 1
    r = []
    for j in range(len(A)):
        if A[j]%2 == 1:
            r.append(str(j))
    print('Case #%d: %s' %((i+1),' '.join(r)))
