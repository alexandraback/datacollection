data = iter(open('B-small-attempt0.in').read().splitlines())
cases = int(next(data))
for case in range(1, cases + 1):
    ans, s = 0, next(data).rstrip('+')
    while s:
        ans = ans + 2 if s.startswith('+') else 1
        s = s.lstrip('+')[::-1].replace('+', '.').replace('-', '+').replace('.', '-').rstrip('+')
    print "Case #%d: %d" % (case, ans)

