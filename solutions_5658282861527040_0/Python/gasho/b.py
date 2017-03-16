#!/usr/bin/env python


def main():
    n_tests = int(raw_input())
    for test in xrange(1, n_tests + 1):
        A, B, K = map(int, raw_input().split())
        result = 0
        for a in xrange(A):
            for b in xrange(B):
                if a & b < K:
                    result += 1
        print 'Case #%d: %d' % (test, result)


if __name__ == '__main__':
    main()
