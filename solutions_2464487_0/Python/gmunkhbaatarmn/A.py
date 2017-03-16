import sys
sys.stdin = open("input.txt")
sys.stdout = open("output.txt", "w+")

t_case = input()

for i in xrange(t_case):
    R, T = raw_input().split()
    R, T = int(R), int(T)

    ans = 0
    d = (R+1) ** 2 - R ** 2
    ll, rr = 0, T

    while True:
        mm = (ll + rr + 1) / 2
        mx = mm + 1
        # print ll, mm, rr
        if (2 * mm + d) * (mm + 1) <= T < (2 * mx + d) * (mx + 1):
            ans = mm + 1
            break
        elif (2 * mm + d) * (mm + 1) > T:
            rr = mm - 1
        else:
            ll = mm + 1

    print "Case #%s: %s" % (i+1, ans)
