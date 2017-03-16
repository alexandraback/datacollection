def core():
    B, M = map(int, raw_input().split())

    d = 2 ** (B - 2) - M
    if B == 2:
        if M == 1:
            print "POSSIBLE"
            print "01"
            print "00"
        else:
            print "IMPOSSIBLE"
        return "",
    if d < 0:
        print "IMPOSSIBLE"
        return
    if d == 0:
        print "POSSIBLE"
        for k in xrange(B):
            print "0" * (k + 1) + "1" * (B - k - 1)
        return

    matrix = [[0 for _ in xrange(B)] for _ in xrange(B)]
    for i in xrange(B):
        for j in xrange(i + 1, B - 1):
            matrix[i][j] = 1

    l = 0
    while l <= M:
        # print l, M, M & (1 << l)
        if M & (1 << l) > 0:
            matrix[l + 1][B - 1] = 1
        l += 1
    print "POSSIBLE"
    for t in xrange(B):
        print "".join(map(str, matrix[t]))


T = int(raw_input())
for t in xrange(T):
    print "Case #" + str(t + 1) + ":",
    core()
