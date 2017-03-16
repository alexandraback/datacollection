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
    result = inner(int(string))
    if result is None:
        return "INSOMNIA" # only called if step is 0
    return result

def inner(step):
    from itertools import count
    if step == 0:
        return None
    digits = set()
    for n in count(step, step):
        digits.update(str(n))
        if len(digits) == 10:
            return n
