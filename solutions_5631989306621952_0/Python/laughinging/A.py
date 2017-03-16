f = open("A-small-attempt0.in", "r")
t = int(f.readline().strip())
for i in xrange(t):
    s = f.readline().strip()
    u = ''
    for c in s:
        if u+c > c+u:
            u = u + c
        else:
            u = c + u
    print "Case #" + str(i+1) + ":",
    print u
