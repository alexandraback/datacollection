import sys

lines = sys.stdin.readlines()

ntests = int(lines[0])

linenum = 1;
for c in xrange(0, ntests):
    tokens = lines[linenum].split()
    start_size, num_others = int(tokens[0]), int(tokens[1])
    # print start_size, num_others
    
    other_sizes = sorted([int(x) for x in lines[linenum+1].split()])
    # print other_sizes
    # print

    count = 0;
    min_changes = len(other_sizes)
    for i in xrange(len(other_sizes)):
        if start_size > other_sizes[i]:
            # normal merge
            start_size += other_sizes[i]
        else:
            # print "start:", start_size, "   diff: ", other_sizes[i]-start_size+1

            # if delete everything else
            nlefts = (len(other_sizes)-i)
            min_changes = min(min_changes, count+nlefts)

            if start_size>1:
                # how many to add
                ninserts = 0;
                while start_size<=other_sizes[i]:
                    start_size = start_size*2 - 1
                    ninserts = ninserts + 1
                    # print start_size

                start_size = start_size + other_sizes[i]
                count = count + ninserts
            else:
                count = count + nlefts
                break;

            # start_size += (start_size-1)
            # if start_size > other_sizes[i]:
            #     count = count + 1
            #     start_size += other_sizes[i];
            # else:
            #     count = count + (len(other_sizes)-i)
            #     break;

    min_changes = min(min_changes, count)


    print "Case #" + str(c+1) + ": " + str(min_changes)

    # if (c+1)==11:
    #     exit(1)

    linenum = linenum + 2
