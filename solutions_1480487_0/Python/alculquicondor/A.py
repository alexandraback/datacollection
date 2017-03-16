T = int(raw_input())

for i in range(1,T+1):
    A = [int(x) for x in raw_input().split()]
    n = A[0]
    A = A[1:]
    ans = 'Case #%d:' % (i)
    X = sum(A)
    f = [0] * n
    valid = range(n)
    while True:
        m = len(valid)
        Xp = float(X) + sum(A[i] for i in valid)
        for i in valid:
            f[i] = max(0,(Xp/m-A[i])/X)
        valid = [i for i in valid if f[i]>0.]
        if len(valid)==m:
            break
    for x in f:
        ans += ' '+str(100*x)
    print ans

