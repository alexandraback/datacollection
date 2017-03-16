with open('B-large.in') as f:
    data = [line.rstrip() for line in f]
i = 1
ncase = 1
while i < len(data):
    print "Case #%d:" % ncase,
    C, F, X = [float(j) for j in data[i].split()]
    r = 2.0
    t = 0.0
    if (X <= C):
        t = X / r
    else:
        while True:
            if (X / r) < (C / r) + (X / (r + F)):
                t += X / r
                break
            else:
                t += C / r
                r += F
    print "%.7f" % t
    i += 1
    ncase += 1