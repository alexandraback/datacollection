#!/usr/bin/env python

def solve(k, c, s):
    if s * c >= k:
        ans = []
        for i in xrange(0, k, c):
            n = 1
            for j in xrange(0, min(k - i, c)):
                n += (i + j) * (k ** (c - 1 - j))
            ans.append(n)
        return ' '.join(str(x) for x in ans)
    else:
        return 'IMPOSSIBLE'

if __name__ == "__main__":
    T = input()
    for i in xrange(T):
        K, C, S = map(int, raw_input().split())
        print 'Case #{}: {}'.format(i + 1, solve(K, C, S))