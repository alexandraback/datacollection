import sys

def howManyToAdd(shynessCounts):
    alreadyStanding = 0
    toAdd = 0
    for level, count in enumerate(shynessCounts):
        # Make sure that the people at the current level stand
        if count>0 and alreadyStanding<level:
            toAdd += level-alreadyStanding
            alreadyStanding = level
        # Update for the next iteration
        alreadyStanding += count
    return toAdd

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for i in range(ncases):
        _, shynessString = sys.stdin.readline().split()
        friends = howManyToAdd(int(s) for s in shynessString)
        print "Case #%d: %d" % (i+1, friends)

