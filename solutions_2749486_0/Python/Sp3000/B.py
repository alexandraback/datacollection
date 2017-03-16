infile = open("B-small-attempt0.in", "rU")
outfile = open("B-small-attempt0.out", "w")

linenum = 0
case = 1
for line in infile:
    if linenum != 0:
        l = line.strip().split(" ")
        x = int(l[0])
        y = int(l[1])

        if x > 0:
            char1 = "WE"
        else:
            char1 = "EW"

        if y > 0:
            char2 = "SN"
        else:
            char2 = "NS"

        outfile.write("Case #%d: " % case)
            
        for i in xrange(0, abs(x)):
            outfile.write(char1)

        for j in xrange(0, abs(y)):
            outfile.write(char2)

        outfile.write("\n")
        
        case += 1
    linenum += 1

outfile.close()
