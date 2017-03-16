f = open('A-small-attempt1.in')

T = int(f.readline().strip())
for case in range(T):
    Ns = [int(x) for x in f.readline().strip().split()][1:]
    remain = tot = sum(Ns)
    nums = len(Ns)
    target = float(2 * tot) / nums
    percs = [None for x in Ns]
    while any([x > target for x in Ns]):
        for i, x in enumerate(Ns):
            if x >= target:
                percs[i] = 0
                Ns[i] = 0
                nums -= 1
        remain = sum(Ns)
        target = float(tot + remain) / nums

    for i, x in enumerate(Ns):    
        if percs[i] is None:
            percs[i] = 100 * (float(target - x) / tot)
    print "Case #%d: %s" % (case + 1, ' '.join(str(p) for p in percs))
