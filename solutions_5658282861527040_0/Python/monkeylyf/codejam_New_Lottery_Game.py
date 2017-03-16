"""
"""


def small(A, B, K, t):
    A = min(A, B)
    B = max(A, B)

    pair = 0

    for a in xrange(A):
        for b in xrange(B):
            if a & b < K:
                pair += 1
    print 'Case #{0}: {1}'.format(t, pair)


def main():
    T = int(raw_input())     
    for t in xrange(1, T + 1):
        (A, B, K) = map(int, raw_input().split())
        small(A, B, K, t)


if __name__ == '__main__':
    main()
