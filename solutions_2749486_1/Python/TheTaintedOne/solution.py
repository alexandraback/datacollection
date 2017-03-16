import sys

lines = sys.stdin.readlines()

ntests = int(lines[0])


def dist(tgt, src):
    return abs(tgt[0]-src[0])+abs(tgt[1], tgt[1])


linenum = 1;
for c in xrange(0, ntests):
    xpos, ypos = lines[linenum].split()
    xpos = int(xpos)
    ypos = int(ypos)
    # print xpos, ypos


    max_step = 1
    min_steps = 0
    while min_steps<(abs(xpos)+abs(ypos)):
        min_steps += max_step
        max_step += 1
        # print min_steps

    # print "max: ", max_step


    # N S E W
    success = False
    while not success:
        result = ""
        step = max_step
        xcurr = xpos
        ycurr = ypos
        while step>0 and (xcurr!=0 or ycurr!=0):
            # print "pos: ", xcurr, ycurr
            if xcurr > 0 and (abs(xcurr)>abs(ycurr)):
                xcurr -= step
                step -= 1
                result = "E" + result
                continue

            if xcurr < 0 and (abs(xcurr)>abs(ycurr)):
                xcurr += step
                step -= 1
                result = "W" + result
                continue

            if ycurr > 0:
                ycurr -= step
                step -= 1
                result = "N" + result
                continue

            if ycurr < 0:
                ycurr += step
                step -= 1
                result = "S" + result
                continue

        if xcurr==0 and ycurr==0:
            success = True
        else:
            max_step += 1

    # print "final:", xcurr, ycurr
    # exit(1)
        

    print "Case #" + str(c+1) + ": ", str(result)

    linenum = linenum + 1
