import string
import math
a = ['%00d', '%01d', '%02d', '%03d']
T = int(input())
for cc in range(1,T + 1):
    C, J = input().split()
    n = len(C)
    ans = (1000000, 0)
    for i in range(1000):
        if len(a[n] % i) != n:
            continue
        s1 = a[n] % i
        ok = 1
        for k in range(n):
            if s1[k] != C[k] and C[k] != '?':
                ok = 0
        if ok == 0:
            continue
        for j in range(1000):            
            if len(a[n] % j) != n:
                continue            
            s2 = a[n] % j
            ok = 1
            for k in range(n):
                if s2[k] != J[k] and J[k] != '?':
                    ok = 0
            if ok == 0:
                continue
            if abs(ans[0] - ans[1]) < abs(i - j):
                continue
            elif abs(ans[0] - ans[1]) > abs(i - j):
                ans = [i, j]
            elif ans > [i, j]:
                ans = [i, j]
    ans = [a[n] % ans[0], a[n] % ans[1]]
    print('Case #%d: %s %s' % (cc, ans[0], ans[1]))

