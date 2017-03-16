# Iterate over all amounts
# 0 is possible
# Make copy of possible
# For each currency:
    # Iterate over all possible:
    # Add possible + currency as many times as necessary


# If not possible: Add a coin to that amount, make it possible

# If possible:

# Iterate over all amounts:

# If not possible: Create a coin, iterate over all possible, add possible + currency as many times as necessary



import copy



T = int(raw_input())
for i in xrange(T):
    c, d, v = map(int, raw_input().split())
    currencies = map(int, raw_input().split())
    allPossible = {0}

    for cur in currencies:
        prevAllPossible = copy.copy(allPossible)
#        print prevAllPossible
        for pos in prevAllPossible:
            for amount in xrange(1, c + 1):
                allPossible.add(pos + amount*cur)
#    print allPossible

    ans = 0
    for val in xrange(v+1):
        if val not in allPossible:
            ans += 1
            prevAllPossible = copy.copy(allPossible)
            for pos in prevAllPossible:
                for amount in xrange(1, c + 1):
                    allPossible.add(pos + amount*val)

    print "Case #%s: %s" % (i + 1, ans)
