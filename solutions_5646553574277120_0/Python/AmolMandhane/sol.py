def read(t):
    return t(raw_input().strip())


def read_arr(t):
    return map(t, raw_input().strip().split())


def solve_small():
    C, D, V = read_arr(int)
    den = read_arr(int)
    p = [0]
    for d in den:
        p += filter(lambda x: x <= V, map(lambda x: x + d, p))
    p = sorted(list(set(p)))
    add = 0
    for i in xrange(1, V + 1):
        if i not in p:
            add += 1
            c = 2**(len(bin(i)) - 3)
            p += filter(lambda x: x <= V, map(lambda x: x + c, p))
            p = sorted(list(set(p)))
    return add

solve = solve_small
for T in xrange(input()):
    print "Case #%d:" % (T+1, ),
    print solve()
