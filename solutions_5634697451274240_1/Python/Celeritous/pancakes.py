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
    """Note that there is no need to ever split a contiguous
group of pancakes with the same facing. Thus all strings can be
condensed to alternating sequences of '-' and '+' with no loss
of generality.

In fact once you have this condensed string all you need is the
start symbol and the length, and trailing '+' can be ignored.

This gives us only two cases:

1. start = '-', length odd
2. start = '+', length even

From either of these cases, flipping an even-length segment
leaves the string unchanged (as it is symmetrical after
flipping) and any other flip reduces length by one (after the
next condense and rstrip)."""

    condensed = condense(string.rstrip('+'))
    return len(condensed)

def condense(string):
    from itertools import groupby
    return "".join(c for c, _ in groupby(string))

def flipped(s, n):
    """Only needed for visualisation, answer never uses it."""
    from itertools import chain
    opposite = lambda c:"-" if c == "+" else "+"
    return "".join(chain(map(opposite, s[n - 1::-1]), s[n:]))
