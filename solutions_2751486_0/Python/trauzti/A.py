import sys
consonants = {x : 1 for x in ['a','e','i','o','u']}



for t in xrange(1, 1+int(sys.stdin.readline())):
    l = sys.stdin.readline().split(" ")
    s = l[0]
    n = int(l[1])
    LEN = len(s)
    cool = ""
    for i in xrange(LEN):
        if s[i] in consonants:
            cool += "0"
        else:
            cool += "1"

    mega = "1" * n
    f = 0
    for start in xrange(LEN):
        for end in xrange(start+n,LEN+1):
            sub = cool[start:end]
            if sub.find(mega) >= 0:
                f += 1


    d = f
    print "Case #%d: %d" % (t, d)

