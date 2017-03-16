import sys
import itertools

lines = sys.stdin.readlines()

ntests = int(lines[0])


def countSquares(ndigits):
    if ndigits == 1:
        return [1, 2, 3]

    results = []
    if ndigits%2 == 0:
        # use 2, e.g. 22, 2002
        results.append(2*(10**(ndigits-1))+2);
        # use 1 or 0, e.g. 11, 1001, 1111
        usable = [x for x in xrange(1, ndigits/2)]
        # print "usable ", usable

        base = (10**(ndigits-1))+1
        for d in xrange(0, 4): # can use at most three pair of 1s
            for xs in itertools.combinations(usable, d):
                # print d, xs
                num = base;
                for x in xs:
                    num += 10**x
                    num += 10**(ndigits-x-1)
                results.append(num)
    else:
        mid = (ndigits-1)/2

        # use 2s at the ends, e.g. 202, 212
        results.append(2*(10**(ndigits-1))+2)
        results.append(2*(10**(ndigits-1))+2+(10**mid))

        # use one 2 middle, e.g. 121, 10201, can use 5 mo
        base = (10**(ndigits-1))+1+(2*(10**mid))

        usable = [x for x in xrange(1, ndigits/2)]
        # print usable
        for d in xrange(0, 2): # can use at most one pair of 1s
            for xs in itertools.combinations(usable, d):
                num = base
                for x in xs:
                    num += 10**x
                    num += 10**(ndigits-x-1)
                results.append(num)

        # use 1 or 0, e.g. 101, 111
        base = (10**(ndigits-1))+1
        # first 0 in the middle
        for d in xrange(0, 4): # can use at most three pair of 1s
            for xs in itertools.combinations(usable, d):
                num = base
                for x in xs:
                    num += 10**x
                    num += 10**(ndigits-x-1)
                results.append(num)
                results.append(num+(10**mid))
        

    return results


# generates all fair squares
squares = [];
for d in xrange(1, 51):
    squares.extend(countSquares(d))


# print (len(squares))


for t in xrange(1, ntests+1):
    tokens = lines[t].split();
    lb, ub = int(tokens[0]), int(tokens[1])

    # print lb, ub
    fairs = [x**2 for x in squares if lb<=(x**2) and ub>=(x**2)]

    # print fairs
    print "Case #" + str(t) + ": " + str(len(fairs))
