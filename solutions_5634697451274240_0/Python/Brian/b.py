with open("b.in") as f:
    t = int(next(f))
    for case in xrange(t):
        pancakes = next(f).strip()
        bottom = pancakes[-1]
        swaps = 0
        for i in xrange(len(pancakes)-1):
            if pancakes[i+1] != pancakes[i]:
                swaps += 1

        flips = swaps + (1 if bottom == '-' else 0)
        print "Case #{}: {}".format(case+1, flips)
