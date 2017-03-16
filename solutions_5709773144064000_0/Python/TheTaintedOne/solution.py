import sys
import itertools

lines = sys.stdin.readlines()

ntests = int(lines[0])

curr = 1
for t in range(1, ntests+1):
    C, F, X = [float(x) for x in lines[curr].split()]


    S = 2 # cookie speed
    cumtime = 0
    while True:
        nottime = X/S
        buytime = (C/S) + (X/(S+F))
        if buytime < nottime:
            cumtime += (C/S)
            S += F
        else:
            break


    curr += 1

    print "Case #"+ str(t) + ": %.7f" % (cumtime+nottime)
