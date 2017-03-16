#!/usr/bin/python

import sys


class wall(dict):
    def __missing__(self, key):
        return 0

def brute(TRIBES):
    WALL = wall()
    day = 0
    ans = 0
    while True:
        minday = 99999999999
        ATRIBE = []
        LTRIBE = []
        NWALL = wall(WALL.copy())
        for attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength in TRIBES:
            if numattack == 0:
                continue
            if attackday < minday:
                LTRIBE.extend(ATRIBE)
                ATRIBE = []
                ATRIBE.append(( attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength))
                minday = attackday
            elif attackday == minday:
                ATRIBE.append(( attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength))
            else:
                LTRIBE.append(( attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength))
        if len(ATRIBE) == 0:
            break
#        print 'atribe', ATRIBE
        # process attacks
        for attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength in ATRIBE:
            numattack -= 1
            success = 0
#            print 'attacking', attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength
            assert east-west > 0
            for w in xrange(west,east):
                if WALL[w] < strength:
                    success = 1
                NWALL[w] = max(WALL[w], strength)
            if success:
#                print 'success'
                ans += 1
            strength += deltastrength
            west += deltadir
            east += deltadir
            attackday += deltaday
            LTRIBE.append(( attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength))
        TRIBES = LTRIBE
#        print 'tribes', TRIBES
        WALL=NWALL
    return ans

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
N = int(l)

for CASE in range(1,N+1):
    print 'Case #%d:' % CASE,
    numtribes = data.pop( 0 )
    numtribes = int(numtribes)
    TRIBES = []
    for i in xrange(0,numtribes):
        l = data.pop( 0 )
        attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength = [ int(x) for x in  l.split(' ')]
        TRIBES.append( (attackday, numattack, west, east, strength, deltaday, deltadir, deltastrength ))
#    print TRIBES
    ans = brute(TRIBES)
    print ans

    



