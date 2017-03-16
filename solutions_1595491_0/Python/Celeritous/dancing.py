from __future__ import division

def problem(inPath, outDir = ""):
    def solve(inPath, processor, outDir = ""):
        from multiprocessing import Pool
        from os import path

        inf = open(inPath, 'rU')
        stem = path.basename(inPath)
        name, extension = path.splitext(stem)
        outName = name + ".out"
        outPath = path.join(outDir, outName)
        outf = open(outPath, 'w')

        inf.readline() #discard the line which tells us how many lines of input there are
        pool = Pool()
        outputs = pool.map(processor, (line.strip() for line in inf))
        for i, result in enumerate(outputs, 1):
            string = "Case #%s: %s" % (i, result)
            if i > 1:
                outf.write("\n")
            outf.write(string)

    solve(inPath, processor, outDir)

def processor(string):
    ints = [int(s) for s in string.split(" ")]
    number = ints[0]
    surprising = ints[1]
    minBest = ints[2]
    totals = ints[3:]

    IMPOSSIBLE = 0
    SURPRISING = 1
    CERTAIN = 2

    def rating(total, minBest):
        provisional = []
        n = 3
        running = total
        while n > 0:
            upcoming = running//n
            running -= upcoming
            n -= 1
            provisional.append(upcoming)
        #given the best provisional result and the number of copies of that result, we can work out
        #whether surprisingness is necessary to reach the total and if it is possible
        best = provisional[-1]
        count = provisional.count(best)
        if best >= minBest:
            return CERTAIN
        if best <= minBest - 2 or best == 0 or count < 2:
            return IMPOSSIBLE
        return SURPRISING

    counts = dict((x, 0) for x in xrange(3))
    for t in totals:
        counts[rating(t, minBest)] += 1
    return counts[CERTAIN] + min(counts[SURPRISING], surprising)
