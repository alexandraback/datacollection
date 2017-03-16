import sys

rl = lambda: sys.stdin.readline().strip()


def remove_num_nth(s, t, n):
    for c in t:
        s = s.replace(c, '', n)
    return s



T = int(rl())
for tcase in range(T):
    S = rl()
    print >> sys.stderr, tcase, S

    used_nums = {}
    for orth_ch, c, string in [('G', 8, 'EIGHT'),
                               ('X', 6, 'SIX'),
                               ('W', 2, 'TWO'),
                               ('Z', 0, 'ZERO'),
                               ('U', 4, 'FOUR'),
                               ('F', 5, 'FIVE'),
                               ('V', 7, 'SEVEN'),
                               ('T', 3, 'THREE'),
                               ('I', 9, 'NINE'),
                               ('O', 1, 'ONE')]:
        num = S.count(orth_ch)
        used_nums[c] = num
        # print orth_ch, c, num, S,
        S = remove_num_nth(S, string, num)
        # print S
    ans = [str(k) * v for k, v in sorted(used_nums.items(), key=lambda x: x[0]) if v > 0]
    print 'Case #%d: %s' % (tcase + 1, ''.join(ans))
