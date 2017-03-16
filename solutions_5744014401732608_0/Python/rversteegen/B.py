def ints():
    return [int(x) for x in raw_input().strip().split()]

T = input()
for t in range(T):
    B,M = ints()
    #print B,M

    if M > 2**(B-2):
        print "Case #%d: IMPOSSIBLE" %( t+1)
    else:
        print "Case #%d: POSSIBLE" % (t+1)

        #        ret = [[0] * B for i in range(B)]

        tot = 0
        ret = ["0"]
        MM = M
        if M == 2**(B-2):
            MM = M - 1

        for i in range(B-2)[::-1]:
            if MM & (1 << i):
                ret.append("1")
                tot += 2**i
            else:
                ret.append("0")
        if M == 2**(B-2):
            ret.append("1")
            tot += 1
        else:
            ret.append("0")

        print "".join(ret)

        for i in range(1,B):
            ret = []
            for j in range(B):
                ret.append( "1" if j > i else "0" )
            print "".join(ret)

        assert tot == M

        # for row in ret:
        #     print " ".join(str(x) for x in ret)
