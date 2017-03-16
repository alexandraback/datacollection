# fml

n_cases = input()

for case in xrange(1, n_cases + 1):
    n_levels = int(raw_input())
    levels = [] # [completed, twostar, onestar]
    for _ in range(n_levels):
        a, b = map(int, raw_input().strip().split())
        levels += [[0, b, a]]

    out = 0
    n_stars = 0

    levels.sort(reverse=True)

    while True:
        #print 't: %d #:%d %s' % (out, n_stars, l2sort)
        if n_stars == 2 * n_levels:
            break
        for lev in levels:
            lstate, tworeq, onereq = lev
            if lstate == 0 and tworeq <= n_stars:
                lev[0] = 2
                n_stars += 2
                out += 1
                break
        else:
            for lev in levels:
                lstate, tworeq, onereq = lev
                if lstate == 1 and tworeq <= n_stars:
                    lev[0] = 2
                    n_stars += 1
                    out += 1
                    break
            else:
                for lev in levels:
                    lstate, tworeq, onereq = lev
                    if lstate == 0 and onereq <= n_stars:
                        lev[0] = 1
                        n_stars += 1
                        out += 1
                        break
                else:
                    out = "Too Bad"
                    break

    print "Case #%d: %s" % (case, out)
