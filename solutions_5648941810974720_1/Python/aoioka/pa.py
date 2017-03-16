# -*- coding: utf-8 -*-


def solve():
    s = raw_input()
    counts = {}
    for c in s:
        if c not in counts:
            counts[c] = 0
        counts[c] += 1

    digits = [0] * 10

    target = 'ZERO TWO FOUR SIX'.split()
    target_c = 'Z W U X'.split()
    target_d = [0, 2, 4, 6]
    for i, tc in enumerate(target_c):
        if tc in counts and counts[tc] > 0:
            digits[target_d[i]] += counts[tc]
            cnt = counts[tc]
            for e in target[i]:
                counts[e] -= cnt

    target = 'ONE FIVE SEVEN'.split()
    target_c = 'O F S'.split()
    target_d = [1, 5, 7]
    for i, tc in enumerate(target_c):
        if tc in counts and counts[tc] > 0:
            digits[target_d[i]] += counts[tc]
            cnt = counts[tc]
            for e in target[i]:
                counts[e] -= cnt

    target = 'EIGHT'.split()
    target_c = 'G'.split()
    target_d = [8]
    for i, tc in enumerate(target_c):
        if tc in counts and counts[tc] > 0:
            digits[target_d[i]] += counts[tc]
            cnt = counts[tc]
            for e in target[i]:
                counts[e] -= cnt

    target = 'THREE NINE'.split()
    target_c = 'H I'.split()
    target_d = [3, 9]
    for i, tc in enumerate(target_c):
        if tc in counts and counts[tc] > 0:
            digits[target_d[i]] += counts[tc]
            cnt = counts[tc]
            for e in target[i]:
                counts[e] -= cnt

    ret = []
    for i, d in enumerate(digits):
        ret.extend([i] * d)

    print ''.join(map(str, ret))


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        print 'Case #%d:' % i,
        solve()


if __name__ == '__main__':
    main()
