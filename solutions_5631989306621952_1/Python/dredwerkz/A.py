t = int(raw_input())

for i in xrange(t):
    a = raw_input()
    res = ""
    for c in a:
        if c + res > res + c:
            res = c + res
        else:
            res = res + c
    print "Case #%d: %s" % (i+1, res)
