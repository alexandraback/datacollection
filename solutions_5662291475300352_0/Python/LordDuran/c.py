from pprint import pprint
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

def do_case(ncase):
    num_groups, = parse_line()
    groups = []
    for i in xrange(num_groups):
        groups.append(parse_line())

    total_hikers = sum(g[1] for g in groups)
    if total_hikers <= 1:
        print >>outputfile, out_s % (ncase, str(0))
        return

    if len(groups) == 1:
        start, speed1, speed2 = groups[0][0], groups[0][2], groups[0][2]+1
        if speed1 == speed2:
            print >>outputfile, out_s % (ncase, str(0))
            return
        s1 = float(360) / speed1
        s2 = float(360) / speed2
        t = 360 / (s1 - s2)
        if (360 - start) * t > 360:
            print >>outputfile, out_s % (ncase, str(0))
            return
        print >>outputfile, out_s % (ncase, str(1))
        return

    groups.sort(key= lambda x: x[0]) # Sort by start point
    start1, rate1 = groups[0][0], groups[0][2]
    start2, rate2 = groups[1][0], groups[1][2]

    if rate1 == rate2:
        print >>outputfile, out_s % (ncase, str(0))
        return

    s1 = float(360) / rate1
    s2 = float(360) / rate2
    meet_time = 360 / (max(s2,s1) - min(s2, s1))
    if s2 > s1: # Further guy is faster
        d = start1 - start2
        if d < 0:
            d += 360
        first_meet_time = d/(s2 - s1)
        if first_meet_time > (360 - start2)/s2:
            print >>outputfile, out_s % (ncase, str(0))
            return
        print >>outputfile, out_s % (ncase, str(1))
        return
    if s1 > s2: # Closer guy is faster
        first_meet_time = (start2 - start1)/(s1 - s2)
        if first_meet_time > (360 - start2)/s2:
            print >>outputfile, out_s % (ncase, str(0))
            return
        print >>outputfile, out_s % (ncase, str(1))



T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    do_case(ncase)
    