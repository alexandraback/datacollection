f = open('in.txt')
lines = f.readlines()[1:]

for i in xrange(len(lines)):
    line = lines[i]
    line = line.split()
    N = int(line[0])
    S = int(line[1])
    p = int(line[2])
    points = map(int, line[3:])

    out = 0
    surprisesLeft = S
    
    
    for point in points:
        for attemptP in xrange(p, 11):
            cpoint = point
            cpoint -= attemptP
            split1 = cpoint / 2
            split2 = cpoint - split1
            diff = max((attemptP, split1, split2)) - min((attemptP, split1, split2))
            if diff <= 1 and split1 >= 0 and split2 >= 0:
                #print 'win!'
                out += 1
                break
        else:
            for attemptP in xrange(p, 11):
                cpoint = point
                cpoint -= attemptP
                split1 = cpoint / 2
                split2 = cpoint - split1
                diff = max((attemptP, split1, split2)) - min((attemptP, split1, split2))
                if diff == 2 and surprisesLeft > 0 and split1 >= 0 and split2 >= 0:
                    #print "i'll be nice", diff, attemptP, split1, split2
                    out += 1
                    surprisesLeft -= 1
                    break
    print 'Case #%d: %d' % (i+1, out)
    #raw_input()
