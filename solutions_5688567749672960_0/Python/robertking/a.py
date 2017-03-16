data = iter(open('A-small-attempt1.in').read().splitlines())
cases = int(next(data))

def rev(x):
    s = str(x)[::-1]
    s.lstrip('0')
    return int(s)

for case in range(1, cases + 1):
    n = int(next(data))
    d = [99999999] * (2*10**6 + 1)
    x = 1
    d[1] = 1
    for i in range(2, n+1):
        d[i] = min(d[i], d[i-1] + 1)
        if rev(i) > 2 * 10**6:
            continue
        d[rev(i)] = min(d[rev(i)], d[i] + 1)
    print "Case #%d: %d" % (case, d[n])


