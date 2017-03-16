def solve():
    d = int(input())
    p = map(int, raw_input().split())
    ans = max(p)

    for i in xrange(2, max(p)):
        tmp = list(p)
        t = 0
        for j in xrange(len(tmp)):
            while tmp[j] > i:
               tmp[j] -= i
               t += 1
        ans = min(ans, i + t)
    return ans

T = input()
for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve())
