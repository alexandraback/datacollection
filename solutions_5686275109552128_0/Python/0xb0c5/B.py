def solve(ns):
    m = max(ns)
    best = m
    for n_normal in range(1,m):
        n_special = 0
        for n in ns:
            n_special += (n-1)/n_normal
        total = n_normal + n_special
        if total < best:
            best = total
    return best
        


n_cases = input()

for i in range(1,n_cases+1):
    _ = input()
    ns = map(int, raw_input().split(' '))
    print "Case #%d: %d" % (i, solve(ns))
 