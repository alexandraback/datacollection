data_in = open("B-small-attempt3.in", "r")
data_out = open("ProblemB.out", "w")

T = int(data_in.readline())

for i in xrange(T):
    D = int(data_in.readline())
    c = [int(x) for x in data_in.readline().split()]
    c.sort()
    tmin = c[-1]
    jmin = 0

    for j in xrange(2, tmin-1):
        if tmin < j:
            break
        t = 0
        for k in c:
            if k > j:
                b = k/j
                t += b-1
                if k != b*j:
                    t += 1
        t += j
        if t < tmin:
            tmin = t
            jmin = j
    data_out.write("Case #%d: %d\n"%(i+1, tmin))

data_in.close()
data_out.close()
