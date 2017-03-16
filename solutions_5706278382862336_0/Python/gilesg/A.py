def ints():
    return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
    p, q = map(int, raw_input().split('/'))
    gen = 0
    ans = 1e9
    while gen <= 40:
        gen += 1
        p *= 2
        if p >= q:
            ans = min(ans, gen)
            p -= q
    if p or ans > 40:
        ans = "impossible"
    else:
        ans = str(ans)
    print "Case #%d: %s" % (case_num, ans)
