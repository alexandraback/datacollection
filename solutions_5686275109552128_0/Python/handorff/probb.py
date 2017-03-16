import bisect


def solve(d, p):
    done = True
    done_val = 1
    max_p = 0
    max_idx = -1
    for i, p_i in enumerate(p):
        if p_i != 1 and p_i != 2:
            done = False
        elif p_i == 2:
            done_val = 2
        if p_i > max_p:
            max_p = p_i
            max_idx = i

    if done:
        return done_val

    ret = max_p
    for i in xrange(2, 1 + (max_p / 2)):
        a, b = i, max_p - i
        new_p = p[:]
        new_p[max_idx] = a
        new_p.append(b)
        s = 1 + solve(d, new_p)
        if s < ret:
            ret = s
    return ret

t = int(raw_input())
test_cases = []

for i in xrange(t):
    d = int(raw_input())
    p = map(int, raw_input().split(' '))
    test_cases.append((d, p))

for i in xrange(t):
    d, p = test_cases[i]
    print "Case #%d: %d" % (i + 1, solve(d, p))
