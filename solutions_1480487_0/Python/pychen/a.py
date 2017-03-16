import operator
import functools

T = int(input())
for t in range(T):
    s = list(map(int, input().split()))
    n = s[0]
    s = s[1:]
    sums = sum(s)
    ans = []
    for i in range(n):
        tl = 0
        tr = 1
        for k in range(50):
            tm = (tl + tr) / 2
            vleft = 1 - tm
            st = s[i] + sums * tm
            for j in range(n):
                stt = 0
                if j != i and s[j] < st:
                    stt = (st - s[j]) / sums
                vleft -= stt
            if vleft <= 0:
                tr = tm
            else:
                tl = tm
        ans += [tm * 100]
    print("Case #%d:"%(t + 1), end=' ')
    for i in ans:
        print("%f"%i, end=' ')
    print('\n', end='')

