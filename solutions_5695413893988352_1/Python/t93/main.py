def log(fmt, *args):
    return
    print fmt % tuple(args)

def cached(f):
    cache = {}
    def wrapper(*args):
        k = tuple(args)
        if k in cache:
            return cache[k]
        else:
            v = f(*args)
            cache[k] = v
            return v
    return wrapper

def match(n, s):
    return s == "?" or str(n) == s

inf = float('+inf')

@cached
def solve_min(s, t):
    log("solve_min(%s, %s)", s, t)
    if len(s) == 0:
        return (0, '', '')
    best, ans_s, ans_t = inf, '?', '?'
    for s0 in xrange(10):
        for t0 in xrange(10):
            if match(s0, s[0]) and match(t0, t[0]):
                ans, s1, t1 = solve_min(s[1:], t[1:])
                ans += (t0 - s0) * 10 ** (len(s) - 1)
                if ans < best:
                    best, ans_s, ans_t = ans, str(s0) + s1, str(t0) + t1
    log("%d, %s, %s", best, ans_s, ans_t)
    return best, ans_s, ans_t

@cached
def solve_max(s, t):
    log("solve_max(%s, %s)", s, t)
    if len(s) == 0:
        return (0, '', '')
    best, ans_s, ans_t = -inf, '?', '?'
    for s0 in xrange(10):
        for t0 in xrange(10):
            if match(s0, s[0]) and match(t0, t[0]):
                ans, s1, t1 = solve_max(s[1:], t[1:])
                ans += (t0 - s0) * 10 ** (len(s) - 1)
                if ans > best:
                    best, ans_s, ans_t = ans, str(s0) + s1, str(t0) + t1
    log("%d, %s, %s", best, ans_s, ans_t)
    return best, ans_s, ans_t

@cached
def solve_abs(s, t):
    log("solve_abs(%s, %s)", s, t)
    if len(s) == 0:
        return (0, '', '')
    best, ans_s, ans_t = inf, '?', '?'
    for s0 in xrange(10):
        for t0 in xrange(10):
            if match(s0, s[0]) and match(t0, t[0]):
                if s0 == t0:
                    rec = solve_abs
                elif s0 < t0:
                    rec = solve_min
                elif s0 > t0:
                    rec = solve_max
                ans, s1, t1 = rec(s[1:], t[1:])
                ans += (t0 - s0) * 10 ** (len(s) - 1)
                if abs(ans) < abs(best):
                    best, ans_s, ans_t = ans, str(s0) + s1, str(t0) + t1
    log("%d, %s, %s", best, ans_s, ans_t)
    return best, ans_s, ans_t

def main():
    ts = int(raw_input())
    for ti in xrange(ts):
        s, t = raw_input().split(' ')
        diff, ans_s, ans_t = solve_abs(s, t)
        log("Difference: %d", diff)
        print "Case #%d: %s %s" % (ti + 1, ans_s, ans_t)

main()
