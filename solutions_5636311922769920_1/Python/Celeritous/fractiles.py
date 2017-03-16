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
    try:
        result = list(inner(*map(int, string.split(' '))))
        return " ".join(map(str, result))
    except ValueError:
        return "IMPOSSIBLE"

def inner(K, C, S):
    """Algorithm is quite simple in practice. Imagine the final string
(which we never calculate) is a tree of height C, with K nodes at each
branch. We can refer to these using a tuple of C integers.

(g[0], g[1], g[2], ..., g[C - 1]) refers to the g[0] + K*g[1] +
K**2*g[2] + ... + K**(C - 1)*g[C - 1] element of the final string.
Values of g[x] must be between 0 and K - 1, inclusive.

Such a node is "L" if and only if:
O[g[0]] == O[g[1]] == O[g[2]] == ... == O[g[C - 1]] == "L"
Where O is the original, unknown string.

This means that we can determine the original string contained at least
one "G" by testing:
(s*C, s*C + 1, s*C + 2, ..., s*C + (C - 1))
for all integers s in [0, K/C]

If S < K/C (alternatively, S*C < K), this is impossible."""
    
    if S*C < K:
        raise ValueError("Insufficient data to guess.")
    for s in range(S):
        base = s*C
        if base >= K:
            return
        group = [min(base + i, K - 1) for i in range(C)]
        yield linearIndex(K, group)

def linearIndex(K, groupIndices):
    total = 1
    for i, index in enumerate(groupIndices):
        total += index*K**i
    return total

