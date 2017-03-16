
T = int(input())


def solve(xs):
    tot = 0
    xs += '+'
    for i in range(len(xs) - 1):
        if xs[i] != xs[i + 1]: tot += 1
    return tot


for case in range(1, T + 1):
    xs = raw_input()
    print "Case #%d: %s"%(case, str(solve(xs)))
