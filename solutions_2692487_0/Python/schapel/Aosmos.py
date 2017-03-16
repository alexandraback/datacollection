#!/usr/bin/python3

from sys import argv

def fewest(a, n, motes):
    motes = sorted(motes)
    fewest = n # fewest operations known to be needed so far - remove all!
    added  = 0 # number added so far to get to this point
    i = 0
    while i < n:
        m = motes[i]
        if a > m:
            a += m   # absorb mole
            i += 1   # move to next mole
        else:
            fewest = min(fewest, n - i + added)    # try removing all the larger ones
            added += 1       # also try adding
            a += a - 1       #     largest mole possible
            if added > fewest: break   # give up trying to add because it won't be better than removing
    return min(fewest, n - i + added)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    # Google Code Jam I/O
    infile = open(argv[1])
    cases = int(infile.readline())
    for i in range(cases):
        a, n = map(int, infile.readline().split())
        motes = map(int, infile.readline().split())
        print('Case #{}: {}'.format(i+1, fewest(a, n, motes)))
