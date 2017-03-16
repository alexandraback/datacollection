#!/usr/bin/python
import sys

f_input = open(sys.argv[1])


linenums = int(f_input.readline().rstrip())

for i in xrange(linenums):
    attacks = []
    tribenum = int(f_input.readline().rstrip())
    ## register attacks ##
    for j in xrange(tribenum):
        d,n,w,e,s,dd,dp,ds = map(int, f_input.readline().rstrip().split(" "))
        for attacknum in xrange(n):
            day = d+dd*attacknum
            attacks.append((day, w+dp*attacknum, e+dp*attacknum, s+ds*attacknum))
    attacks.sort()

    ## execute attacks ##
    SIZE = 500
    succeed_count = 0
    nowwalls = [0 for j in xrange(SIZE*2+1)]
    next_wall_deltas = []
    #print attacks
    for attackindex in xrange(len(attacks)):
        this_delta = []
        today, west, east, power = attacks[attackindex]
        for attackpoint in xrange(west*2+SIZE, east*2+1+SIZE):
            if power > nowwalls[attackpoint]:
                this_delta.append((attackpoint, power))
        ## is succeed ? ##
        #print west, east
        #print len(this_delta)
        if(len(this_delta)): succeed_count += 1

        ## wall append ##
        next_wall_deltas += this_delta
        if (attackindex == len(attacks)-1 or (not attacks[attackindex+1][0] == today)):
            for delta in next_wall_deltas:
                if (nowwalls[delta[0]] < delta[1]):
                    nowwalls[delta[0]] = delta[1]
            next_wall_deltas = []

    sys.stdout.write("Case #"+str(i+1)+": "+str(succeed_count)+"\n")


