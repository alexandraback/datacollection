def solve(digs):
    friends = 0
    total = 0

    for i, d in enumerate(digs):
        cur_f = max(0, i - total)
        friends += cur_f
        total += cur_f + d

    return friends

T = int(raw_input())

for i in xrange(T):
    s_max_str, digs_str = raw_input().split()
    s_max = int(s_max_str)

    digs = [int(x) for x in digs_str]

    print 'Case #%d: %d' % (i + 1, solve(digs))
