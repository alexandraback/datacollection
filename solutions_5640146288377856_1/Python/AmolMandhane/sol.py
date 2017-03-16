def read(t):
    return t(raw_input().strip())


def read_arr(t):
    return map(t, raw_input().strip().split())


def solve():
    R, C, W = read_arr(int)
    return R*(C//W) + W - (C % W == 0)

for T in xrange(input()):
    print "Case #%d:" % (T+1, ),
    print solve()
