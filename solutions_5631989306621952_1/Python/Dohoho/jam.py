n = int(raw_input())
for ii in xrange(n):
    s = raw_input()
    s2 = s[0]
    for c in s[1:]:
        if c >= s2[0]:
            s2 = c + s2
        else:
            s2 += c
    print "Case #%d: %s" % (ii+1, s2)