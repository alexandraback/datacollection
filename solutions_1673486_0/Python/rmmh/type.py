n_cases = input()

for case in xrange(1, n_cases + 1):
    a, b = map(int, raw_input().strip().split())
    probs = [1.0] + map(float, raw_input().strip().split())

    out = b + 2
    p = 1.0
    for n in xrange(0, a + 1):
        p *= probs[n]
        count = (a - n) + (b - n) + 1
        countwrong = count + b + 1
        e = count * p + countwrong * (1 - p)
        out = min(e, out)

    print "Case #%d: %.6f" % (case, out)
