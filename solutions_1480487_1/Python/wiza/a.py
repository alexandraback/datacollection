case = 0
T = input()

for t in range(T):
    case += 1
    cin = raw_input().split()
    n = int(cin[0])
    arr = [0.0] * (n+2)
    ans = [0.0] * (n+2)
    s = 0.0
    for i in range(1, n+1):
        arr[i] = float(cin[i])
        s += arr[i]
    d = s * 2 / n
    s2 = s * 2
    m = n
    for i in range(1, n+1):
        if arr[i] >= d:
            s2 -= arr[i]
            m -= 1
    d2 = s2 / m
    for i in range(1, n+1):
        if arr[i] >= d2:
            ans[i] = 0.0
        else:
            ans[i] = (d2 - arr[i]) * 100 / s
    print 'Case #' + str(case) + ':',
    for i in range(1,n):
        print '%.6f' % ans[i],
    print '%.6f' % ans[n]
    
