T = int(raw_input())

for case in xrange(1, T+1):
    smax, S = raw_input().split()
    friends, stand = 0, 0
    for si in xrange(len(S)):
        if stand < si:
            friends += si - stand
            stand = si
        stand += (ord(S[si]) - ord('0'))
    print "Case #{}: {}".format(case, friends)
