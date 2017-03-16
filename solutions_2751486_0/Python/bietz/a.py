
if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T+1):
        s, n = raw_input().split()
        n = int(n)

        start = -1
        start_old = -1
        res = 0
        for i, c in enumerate(s):
            if c in ['a', 'e', 'i', 'o', 'u']:
                start = i
                continue
            end = i
            if end - start >= n:
                res += (1 + end - n - start_old) * (len(s) - end)
                start_old = end - n + 1

        print 'Case #{}: {}'.format(t, res)
