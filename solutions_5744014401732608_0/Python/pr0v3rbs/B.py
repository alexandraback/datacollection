


for test in range(1, input() + 1):
    B, M = raw_input().split()
    B = int(B)
    M = int(M)

    # possible
    if M <= 2**(B-2):
        l = []
        t = 2**(B-3)

        for i in range(B - 1):
            if M > t:
                l.append(1)
                M -= t
            else:
                l.append(0)
            t /= 2

        print "Case #" + str(test) + ": POSSIBLE"
        r = '0'
        for i in l:
            r += str(i)
        print r
        for i in range(B - 1):
            print '0' + '0' * (i + 1) + '1' * (B - 2 - i)
    else:
        print "Case #" + str(test) + ": IMPOSSIBLE"
