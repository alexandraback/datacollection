import bisect

if __name__ == '__main__':
    pairs = {}
    for i in xrange(1, 2000000):
        s = str(i)
        for j in xrange(1, len(s)):
            t = int(s[j:] + s[:j])
            if i < t <= 2000000:
                pairs[(i,t)] = 1

    pairs = pairs.keys()
    pairs.sort()

    for caseno in xrange(int(raw_input())):
        A, B = [int(s) for s in raw_input().split()]

        cnt = 0
        lo = bisect.bisect_left(pairs, (A, 0))
        hi = bisect.bisect_right(pairs, (B + 1, 0))
        cnt = sum(1 for n, m in pairs[lo:hi] if A <= n < m <= B)

        print 'Case #%d: %d' % (caseno + 1, cnt)
