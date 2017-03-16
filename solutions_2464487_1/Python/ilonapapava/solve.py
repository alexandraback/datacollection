	

    infile = "A.txt"
    outfile = "ans.txt"
    FIN = open(infile)
    FOUT = open(outfile, "w")
    tt = int(FIN.readline())
    for i in range(tt):
        r, t = map(int, FIN.readline().split())
        l = 1
        ri = 1000000000
        while (ri - l > 1):
            m = (l + ri) // 2
			q = (2 * m - 1) * m + 2 * m * r
            if (q <= t):
                l = m
            else:
                ri = m
        FOUT.write("Case #" + str(i + 1) + ": " + str(l) + "\n")

