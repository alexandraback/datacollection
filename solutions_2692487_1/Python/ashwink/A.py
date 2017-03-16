import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    (A, N) = [int(x) for x in f.readline().split()]
    motes = [int(x) for x in f.readline().split()]

    best = [N for i in range(0, N)]
    adds = 0
    motes.sort()
    #print "motes: %s" % motes
    for (i, mote) in enumerate(motes):
        #print "A: %d" % A
        #print "mote: %d" % mote
        if A > mote:
            A += mote
            best[i] = adds + N - i - 1
        else:
            if A == 1:
                best[i] = N - i
                break
            # option1: drop everything including this mote
            option1 = adds + N - i
            # option2: add motes to raise A above this mote
            #          then drop everything else
            while A <= mote:
                A += A - 1
                adds += 1
            A += mote
            option2 = adds + N - i - 1
            best[i] = min(option1, option2)
        #print "adds: %d" % adds
        #print "best: %s" % best
    
    print "Case #%d: %d" % (case + 1, min(best))
    sys.stdout.flush()
