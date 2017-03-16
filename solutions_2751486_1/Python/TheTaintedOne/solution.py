import sys

lines = sys.stdin.readlines()

ntests = int(lines[0])

vowels = set(["a", "e", "i", "o", "u"])

linenum = 1;
for c in xrange(0, ntests):
    name, csize = lines[linenum].split()
    csize = int(csize)
    # print "[" + name + "]"
    # print start_size, num_others

    cons = [];
    for cc in name:
        if cc in vowels:
            cons.append(0)
        else:
            cons.append(1)

    # print cons


    runs = [];
    curr_run = 0;
    for pos in xrange(len(name)):
        if cons[pos]==1:
            curr_run = curr_run + 1
        else:
            curr_run = 0

        if curr_run>= csize:
            runs.append((pos, curr_run))

    # print runs

    res = 0
    list_pos = 0
    for pos in xrange(len(name)):
        if list_pos < len(runs):
            if pos>runs[list_pos][0]-csize+1:
                list_pos = list_pos+1

            if list_pos < len(runs):
                res = res + (len(name)-runs[list_pos][0])

                # print pos, runs[list_pos]



        


    print "Case #" + str(c+1) + ": ", str(res)

    linenum = linenum + 1
