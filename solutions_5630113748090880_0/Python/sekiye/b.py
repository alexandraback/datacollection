import itertools

def solve():
    N = int(raw_input())
    l = []
    index = range(2 * N - 1)
    for i in xrange(2 * N - 1):
        x = map(int, raw_input().split())
        l.append(tuple(x))
    l.sort()
    for y in itertools.combinations(index, N):
        w = []
        for i in xrange(len(l)):
            if i not in y:
                w.append(l[i])
        s = []
        for i in xrange(N):
            z = tuple([l[index[j]][i] for j in y])
            if z not in w:
                s.append(z)
                if len(s) > 1:
                    break
        if len(s) == 1:
            ans = ''
            for i in s[0]:
                ans += str(i) + ' '
            return ans[:-1]

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
