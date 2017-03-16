
from sys import stdin

T = int(stdin.readline())
for loop in range(1, T+1):
    a, n = [int(x) for x in stdin.readline().split()]
    #print a, n
    bins = [int(x) for x in stdin.readline().split()]
    bins.sort()
    #print bins
    ans = n
    cur = 0
    for i in range(n):
        if a > bins[i]:
            a += bins[i]
        else:
            ans = min(ans, cur+n-i)
            while a <= bins[i] and cur < ans:
                a = a * 2 - 1
                cur += 1
            a += bins[i]
        if cur >= ans:
            break
    ans = min(ans, cur)
    print 'Case #' + str(loop) + ': ' + str(ans)

