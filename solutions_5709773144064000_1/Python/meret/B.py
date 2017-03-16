d = int(raw_input())

for case_no in range(1, d + 1):
    c, f, x = map(float, raw_input().split())
    prod = 2.0
    time = 0.0
    result = 10**50
    for n_farms in range(0, 100005):
        result = min(result, time + x / prod)
        time += c / prod
        prod += f
    print "Case #%d:" % case_no, "%.7f" % result
