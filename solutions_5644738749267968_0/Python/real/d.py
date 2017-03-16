import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

read_floats = lambda: map(float, raw_input().split())


for no_t in xrange(1, read_int() + 1):
    n = read_int()
    a = read_floats()
    b = read_floats()

    l = [(_, 'A') for _ in a] + [(_, 'B') for _ in b]
    l.sort()
    l = [ch for _, ch in l]

    # standard
    l1 = l[:]
    ans1 = 0
    for _ in xrange(n):
        idx = ''.join(l1).rfind('A')

        try:
            idx2 = l1.index('B', idx + 1)
        except:
            idx2 = l1.index('B')
            ans1 += 1

        l1[idx] = l1[idx2] = '_'

    # cheat
    ans2 = 0
    for _ in xrange(n):
        idx_a = l.index('A')
        idx_b = l.index('B')

        if idx_a > idx_b:
            ans2 += 1
        else:
            # cheat
            idx_b = ''.join(l).rfind('B')

        l[idx_a] = l[idx_b] = '_'

    print 'Case #%d: %s %s' % (no_t, ans2, ans1)
