fIn = open("in.txt", "r")
fOut = open("out.txt", "w")
t = int(fIn.readline())
for i in range(1, t+1):
    c, f, x = [float(x) for x in fIn.readline().split()]
    n = 0
    tFactory = 0
    t2 = x/(2+f*n)
    t = tFactory + t2
    while True:
        tFactory += c/(2+f*n)
        n += 1
        t2 = x/(2+f*n)
        tNew = tFactory+t2
        if t-tNew < 0.0000000001:
            break
        t = tNew
    fOut.write("Case #{:d}: {:.7f}\n".format(i, t))