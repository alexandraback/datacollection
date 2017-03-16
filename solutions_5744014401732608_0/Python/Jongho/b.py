cases = int(raw_input())
for c in xrange(cases):
    B,M = map(int, raw_input().split())
    if M>pow(2,B-2):
        print "Case #%d: IMPOSSIBLE" % (c+1)
    else:
        print "Case #%d: POSSIBLE" % (c+1)
        for i in xrange(B-1):
            line = "0"*(i+1)
            for j in xrange(B-i-2):
                if (M-1)>>(i+j) & 0x1 == 1:
                    line+="1"
                else:
                    line+="0"
            if (M>>i & 0x1) or ((M-1)>>i & 0x1) == 1:
                line+="1"
            else:
                line+="0"
            print line
        print "0"*B
