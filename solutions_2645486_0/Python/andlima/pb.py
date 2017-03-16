def solve(e, r, n, v):
    gain = [0 for remaining in xrange(e + 1)]
    before_range = [e]
    for vi in v:
        tmp = [0 for remaining in xrange(e + 1)]
        for before in before_range:
            for spent in xrange(before + 1):
                after = min(before-spent+r, e)
                tmp[after] = max(tmp[after], gain[before] + vi * spent)
        gain = tmp
        before_range = xrange(r, e + 1)
    return max(gain)

def main():
    T = int(raw_input())
    for t in range(T):
        e, r, n = map(int, raw_input().split())
        v = map(int, raw_input().split())
        print 'Case #%d: %d' % (t + 1, solve(e, r, n, v))

main()
