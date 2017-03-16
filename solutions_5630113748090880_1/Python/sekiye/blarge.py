import itertools

def solve():
    N = int(raw_input())
    l = []
    count = [0] * 2501
    for i in xrange(2 * N - 1):
        x = map(int, raw_input().split())
        for y in x:
            count[y] += 1
        l.append(tuple(x))
    n = []
    for i in xrange(len(count)):
        if count[i] % 2 == 1:
            n.append(i)
    ans = ''
    for i in n:
        ans += str(i) + " "
    return ans[:-1]

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
