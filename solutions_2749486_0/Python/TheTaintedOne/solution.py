import sys

lines = sys.stdin.readlines()

ntests = int(lines[0])

linenum = 1;
for c in xrange(0, ntests):
    xpos, ypos = lines[linenum].split()
    xpos = int(xpos)
    ypos = int(ypos)
    # print xpos, ypos


    step = 1

    xcurr = 0
    ycurr = 0
    result = ""
    while xcurr<xpos or ycurr<ypos:
        # print xcurr, ycurr
        if xcurr<xpos:
            result += "E"
            xcurr += step
            step += 1
        if ycurr<ypos:
            result += "N"
            ycurr += step
            step += 1

    for x in xrange(0, xcurr-xpos):
        xcurr -= 1
        result += "EW"

    for y in xrange(0, ycurr-ypos):
        ycurr -= 1
        result += "NS"

    # print xpos, ypos
    # print xcurr, ycurr
    print len(result)


    print "Case #" + str(c+1) + ": ", str(result)

    linenum = linenum + 1
