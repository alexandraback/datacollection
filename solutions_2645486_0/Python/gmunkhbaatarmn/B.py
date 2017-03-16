import sys
sys.stdin = open("input.txt")
sys.stdout = open("output.txt", "w+")

T = input()
for t_case in xrange(T):
    ans = 0
    E, R, N = map(int, raw_input().split())
    nn = map(int, raw_input().split())

    if E > R:
        e = E
        mx = max(nn)
        max_last_idx = 0

        for i in xrange(len(nn)):
            mx, n = max(nn[i:]), nn[i]
            if n == mx:
                ans += e * n
                e = R
                continue
            if e == E:
                ans += R * n
                continue
            if e + R > E:
                ans += (e + R - E) * n
                e = E
            else:
                e += R
    elif E <= R:
        ans += sum(nn) * E

    print "Case #%s: %s" % (t_case+1, ans)
