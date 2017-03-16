t = int(raw_input())

def run(n, c):
    half = n/2
    for i in xrange(c):
        s = "{0:b}".format(i)
        s = ("0" * (half - len(s) - 1)) + s + "1"
        print s[::-1] + ("0" if n%2 else "") + s + " " + " ".join(str(i) for i in xrange(3, 12))

for i in xrange(t):
    s = raw_input().strip().split(" ")
    n = int(s[0])
    c = int(s[1])
    print "Case #%d:" % (i+1)
    run(n, c)
