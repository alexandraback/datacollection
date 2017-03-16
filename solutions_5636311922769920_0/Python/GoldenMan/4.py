t = input()
for test in range(t):
    print "Case #" + str(test + 1) + ":",
    k, c, s = (int(i) for i in raw_input().split(' '))
    p = k / c
    if (k % c) > 0:
        p += 1
    if p > s:
        print "IMPOSSIBLE"
        continue
    for it in range(p):
        cur = c * it + 1
        l = k
        for i in range(c - 1):
            l *= k
            cur = (cur - 1) * k + min((c * it + i + 2), k)
            if cur > l:
                print "ERROR!"
                cur = l
        print cur,
    print

