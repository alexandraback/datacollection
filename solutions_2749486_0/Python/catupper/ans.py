T = input()

for t in xrange(1, T + 1):
    x, y = map(int, raw_input().split())
    res = ""
    if(x > 0):
        res += "WE" * x
    else:
        res += "EW" * -x
    if(y > 0):
        res += "SN" * y
    else:
        res += "NS" * -y
    print "Case #%d: %s"%(t,res)

