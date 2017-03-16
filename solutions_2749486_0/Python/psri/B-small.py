N = int(raw_input())

for I in xrange(1, N+1):
    s = raw_input()
    [x, y] = map(int, s.split(" "))
    t = ""
    if x < 0:
        t = t + ("EW"*(-x))
    else:
        t = t + ("WE"*x)
    if y < 0:
        t = t + ("NS"*(-y))
    else:
        t = t + ("SN"*y)
    print "Case #{0}: {1}".format(I, t)



