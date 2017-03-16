def solve():
    C, D, V = map(int, raw_input().split())
    coins = map(int, raw_input().split())

    def check(coins2):
        s = set()
        for i in xrange(1 << len(coins2)):
            c = 0
            for j in xrange(len(coins2)):
                if i & (1 << j):
                    c += coins2[j]
            s.add(c)
        for i in xrange(1, V + 1):
            if i not in s:
                return i
        return V + 1

    c = 0
    while True:
        smallest = check(coins)
        if smallest == V + 1:
            break
        coins.append(smallest)
        c += 1
    return c

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()

