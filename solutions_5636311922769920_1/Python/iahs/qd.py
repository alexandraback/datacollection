ncases = int(raw_input())
for case in range(ncases):
    k, c, s = map(int, raw_input().split(' '))
    if c == 1:
        if s < k:
            print "Case #%d: IMPOSSIBLE" % (case+1)
        else:
            print ("Case #%d: " % (case+1)) + " ".join(map(str, range(1,s+1)))
    else:
        if s < k:
            print "Case #%d: IMPOSSIBLE" % (case+1)
        elif s == k - 1:
            print ("Case #%d: " % (case+1)) + " ".join(map(str, range(2,k+1)))
        else:
            print ("Case #%d: " % (case+1)) + " ".join(map(str, range(1,s+1)))
