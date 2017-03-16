import sys

def neededDivisions(num, limit):
    """Returns the number by which 'num' should be divided, such that the quotient will be at most 'limit'."""
    return (num+limit-1) / limit

def bestTime(amounts):
    # We can easily see that all the special minutes can be at the beginning of the meal, without
    # impairing the optimal solution (but maybe impairing the diners' patience...)
    # The total time is S+L, where S is the number of special minutes, and L is the largest number
    # of pancakes that remain for any diner.
    # Since the problem limits are quite small, I loop over every possible L and calculate the number
    # of special minutes S needed to obtain that L.
    origMax = max(amounts)
    best = origMax
    for limit in range(1, origMax):
        specials = sum( neededDivisions(amount, limit) - 1 for amount in amounts )
        if limit + specials < best:
            best = limit + specials
    return best

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for i in range(ncases):
        diners = int(sys.stdin.readline())
        amounts = [int(part) for part in sys.stdin.readline().split()]
        assert len(amounts) == diners
        print "Case #%d: %d" % (i+1, bestTime(amounts))

