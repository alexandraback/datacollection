file = open("D-small-attempt0.in", "r")
a = file.readlines()
T = int(a[0])
for i in xrange(1, len(a)):
    t = a[i].split(" ")
    print "Case #%d:" % i,
    for i in xrange(int(t[2])):
        print i + 1,
    print
