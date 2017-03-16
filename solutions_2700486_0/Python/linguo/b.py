def parse(inFile):
    return tuple(inFile.getInts())

a_cache = {}

def ans(r, num):
    if not a_cache.has_key((r, num)):
        if (num == 0):
            return 1.0
        if (num == r):
            return 1.0 / (1 << r)
        a_cache[(r, num)] = (ans(r-1, num-1) + ans(r-1, num)) / 2
    return a_cache[(r, num)]

def solve((N,X,Y)):
    if (X <= 0):
        X = -X
    lvl = (X + Y) / 2
    # points will be added in increasing level
    # there is 1 point with lvl = 0
    # there are 5 points with lvl = 1
    # there are 9 points with lvl = 2

    # and so on

    # sum(4*k+1,{k,0,lvl}) = 2 * lvl * lvl + 3 * lvl + 1

    if (N >= 2 * lvl * lvl + 3 * lvl + 1):
        return "1"
    if (N <= 2 * (lvl - 1) * (lvl - 1) + 3 * (lvl - 1) + 1):
        return "0"
    if (X == 0):
        return "0"

    r = N - (2 * (lvl - 1) * (lvl - 1) + 3 * (lvl - 1) + 1)

    # There are r coin flips
    # Any heads after the first 2 * lvl heads are considered tails
    # What is the probability that there is at least (Y + 1) tails

    if False:
        print "There are %d coin flips. Any heads after the first %d heads are considered tails. What is the probability that there are at least %d tails." % (r, 2 * lvl, Y + 1)

    if (r <= Y):
        return "0"
    if (r >= Y + 2 * lvl + 1):
        return "1"

    # If we are here, then if there have been at least 2 * lvl heads, there are not at least (Y + 1) tails.
    # So we can ignore that stanza

    return str(ans(r, Y + 1))

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2013_1b/b", "B").run()
