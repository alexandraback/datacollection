f = open('A-large.in')
tests = list(f)[1:]
for i, test in enumerate(tests):
    n, vals = test.strip().split()
    count = 0
    standing = 0
    for needed, val in enumerate(vals):
        val = int(val)
        if standing >= needed:
            standing += val
        else:
            count += needed-standing
            standing = needed + val
    print('Case #%d: %d' % (i+1, count))
