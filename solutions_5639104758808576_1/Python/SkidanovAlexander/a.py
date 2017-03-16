for t in range(int(raw_input())):
    a, b = raw_input().split()
    total = 0
    want = 0
    for i, c in enumerate(b):
        if total < i and b[i] != '0':
            want += i - total
            total = i
        total += int(c)

    print "Case #%d: %d" % (t + 1, want)
