outfile = open("b_out.txt", "w")
count = 0
for line in open("B-small-attempt0.in", "rU"):
    if count != 0:
        line = line.strip()
        listy = line.split(" ")
        surp = int(listy[1])
        p = int(listy[2])
        normallimit = 3*p - 2
        if p == 1:
            lowerlimit = 1
        else:
            lowerlimit = 3*p - 4
        scores = listy[3:]
        total = 0
        ncount = 0 #would be normal scores and still get >= p
        scount = 0 #would have to be surprising scores
        for score in scores:
            intscore = int(score)
            if intscore >= normallimit:
                ncount += 1
            elif intscore >= lowerlimit:
                scount += 1
        outfile.write("Case #" + str(count) + ": " + str(ncount + min(surp, scount)) + "\n")
    count += 1
outfile.close()
