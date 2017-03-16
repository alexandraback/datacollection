import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

for no_t in xrange(1, read_int() + 1):
    x, r, c = read_ints()
    if r * c % x != 0:
        ans = False
    elif x <= 2:
        ans = True
    elif x == 3:
        ans = min(r, c) > 1
    elif x == 4:
        ans = min(r, c) > 2
    print 'Case #%d: %s' % (no_t, 'GABRIEL' if ans else 'RICHARD')
