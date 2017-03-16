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
    a, b = [int(s) for s in string.split(" ")]

    counts = {}
    for p in xrange(a, b + 1):
        s = str(p)
        M = max(s)
        m = min(s)
        if m == M:
            continue
        added = False
        for c in cycles(s):
            if c in counts:
                added = True
                counts[c] += 1
                break
        if not added:
            counts[s] = 1

    return sum(handshakes(v) for k, v in counts.iteritems())

def cycles(s):
    for i in xrange(len(s)):
        yield s[i:] + s[:i]

def handshakes(n):
    return n*(n - 1)//2
