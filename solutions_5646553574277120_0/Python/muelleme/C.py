import sys
import itertools

f = open(sys.argv[1])
n = int(f.readline())

for t in xrange(1,n+1):
    s = f.readline().strip("\n").split(" ")
    c = int(s[0])
    d = int(s[1])
    v = int(s[2]) 
    reach = set()
    reach.add(0)

    coins = [ int(x) for x in f.readline().strip("\n").split(" ") ]
    for i in coins:
        newreach = set()
        for r in reach:
            for copies in xrange(1,c+1):
                newreach.add(r + copies*i)
        reach.update(newreach)
#    print "reachable:"
#    print reach
#    print "not reachable"
    notreach = set(xrange(1,v+1)).difference(reach)


#    print notreach 
#    maxdiff = 0
#    for x in notreach:
#        for diff in xrange(1,x+1):
#            if x-diff in reach or x-diff == 0:
#                if x-diff > maxdiff:
#                    maxdiff = x-diff

    
    if len(notreach) == 0:
        print "Case #%d: %d" % (t,0)
    else:
        br = False
        possiblecoins = set(range(1,31)).difference(set(coins))
        for i in xrange(1,len(possiblecoins)+1):
            if br:
                break
            newcoinsets = list(itertools.combinations(possiblecoins, i))
            newreach = set()
            #print "Checking coinsets of size:"
            #print i
            for ncs in newcoinsets:
                #print "checking"
                #print ncs
                newreach = set()
                for coin in ncs:
                    newreach2 = set()
                    for x in reach.union(newreach):
                        for copies in xrange(1,c+1):
                            newreach2.add(x + copies*coin)
                    newreach.update(newreach2)
                #print "not reachable"
                notreach = set(range(1,v+1)).difference(reach.union(newreach))
                #print notreach
                #print len(notreach)
                if len(notreach) == 0:
                #if len(xrange(1,v+1).difference(reach.union(newreach))) == 0:
                    print "Case #%d: %d" % (t,i)
                    br = True
                    break



                    









#    coinsadded = 0
#    maxcount = 0
#    maxcoin = 0
#    while len(notreach) > 0:
#        #print "notreachable:"
#        #print notreach
#        maxcount = 0
#        maxcoin = 0
#
#        for nc in xrange(1,v+1):
#            if nc in coins:
#                continue
#            else:
#                count = 0
#                for x in notreach:
#                    reachable = False
#                    for copies in xrange(1,c+1):
#                        if x - copies * nc in reach:
#                            reachable = True
#                            break
#                    if reachable:
#                        count += 1
#                
#                if count > maxcount:
#                    maxcount = count
#                    maxcoin = nc
#
#        #print "adding coin:"
#        #print maxcoin
#
#        coins.append(maxcoin)
#        newreach = set()
#        for x in notreach:
#            for copies in xrange(1,c+1): 
#                if x - copies * maxcoin in reach:
#                    newreach.add(x)
#        coinsadded += 1
#        reach.update(newreach)
#        notreach = set(xrange(1,v+1)).difference(reach)


#    print "Case #%d: %d" % (t,coinsadded)


        










