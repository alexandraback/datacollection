from collections import defaultdict

t = int(raw_input())
for case in range(1, t + 1):
    l, r = raw_input().strip().split()

    # go from l -> r
    i = 0

    def decide():
        # returns l_dig, r_dig, left_is_maxing
        if l[i] == "?" and r[i] == "?":
            if i == len(l) - 1 or (l[i + 1] == "?" or r[i + 1] == "?"):
                # We are at the end, both are the same
                return 0, 0, None
            # Other hard stuff with lookahead of 1. This will also decide maxing or not
            if l[i + 1] == r[i + 1]:
                return 0, 0, None
            if 1 <= int(r[i + 1]) - int(l[i + 1]) <= 5:
                return 0, 0, True
            elif int(r[i + 1]) - int(l[i + 1]) > 5:
                return 1, 0, False

            if 1 <= int(l[i + 1]) - int(r[i + 1]) <= 5:
                return 0, 0, False
            elif int(l[i + 1]) - int(r[i + 1]) > 5:
                return 0, 1, True
        elif l[i] != "?" and r[i] != "?":
            # copy and determine
            if l[i] == r[i]:
                s = None
            else:
                s = int(l[i]) < int(r[i])
            return l[i], r[i], s
        else:
            # One side is determined, we might need to go up or down though
            # Get new
            l_s = l[i:i + 2]
            r_s = r[i:i + 2]
            if len(l_s) == 1 or l_s[-1] == "?" or r_s[-1] == "?":
                if l_s[0] == "?":
                    return r_s[0], r_s[0], None
                else:
                    return l_s[0], l_s[0], None

            def matches(n, t):
                n = str(n)
                while len(n) < len(t):
                    n = "0" + n
                if len(n) > len(t):
                    return False

                for i, x in enumerate(t):
                    if x == n[i] or x == "?":
                        continue
                    return False
                return True

            best = 99, 99
            best_diff = 100
            for x in xrange(100):
                for y in xrange(100):
                    if not matches(x, l_s) or not matches(y, r_s):
                        continue
                    if abs(x - y) <= best_diff:
                        if abs(x - y) == best_diff:
                            if x < best[0]:
                                best = (x, y)
                            elif x == best[0] and y < best[1]:
                                best = (x, y)
                        else:
                            best = (x, y)
                        best_diff = abs(x - y)

            best_strs = [str(x) for x in best]
            # nprint best_strs
            for x in range(2):
                while len(best_strs[x]) < 2:
                    best_strs[x] = "0" + best_strs[x]

            if best_strs[0][0] == best_strs[1][0]:
                to_return = None
            else:
                to_return = best[0] < best[1]

            return best_strs[0][0], best_strs[1][0], to_return

    left_is_maxing = None
    l_ans, r_ans = "", ""
    while left_is_maxing is None and i < len(l):
        l_dig, r_dig, left_is_maxing = decide()
        l_ans += str(l_dig)
        r_ans += str(r_dig)
        i += 1

    def get_rest(t, start, fill="0"):
        z = ""
        for x in xrange(start, len(l)):
            if t[x] == "?":
                z += fill
            else:
                z += t[x]
        return z

    if left_is_maxing:
        l_ans += get_rest(l, i, "9")
        r_ans += get_rest(r, i, "0")
    else:
        l_ans += get_rest(l, i, "0")
        r_ans += get_rest(r, i, "9")

    # Lets try brute forcing!
    best = 999, 999
    best_diff = 1000
    def matches(n, t):
        n = str(n)
        while len(n) < len(t):
            n = "0" + n
        if len(n) > len(t):
            return False

        for i, x in enumerate(t):
            if x == n[i] or x == "?":
                continue
            return False
        return True

    assert matches(19, "1?")

    for x in range(1000):
        for y in range(1000):
            if matches(x, l) and matches(y, r):
                if abs(x - y) <= best_diff:
                    if abs(x - y) == best_diff:
                        if x < best[0]:
                            best = (x, y)
                        elif x == best[0] and y < best[1]:
                            best = (x, y)
                    else:
                        best = (x, y)
                    best_diff = abs(x - y)

    #
    #if best[0] != int(l_ans) or best[1] != int(r_ans):
    #    raise Exception(l_ans, r_ans, best, l, r)
    best_strs = [str(x) for x in best]
    for i in range(2):
        while len(best_strs[i]) < len(l):
            best_strs[i] = "0" + best_strs[i]

    print "Case #%s: %s %s" % (case, best_strs[0], best_strs[1])
