from __future__ import division

MAPPING = { 'y':'a', 'e':'o', 'q':'z', 'z':'q', ' ':' ' }
def train(ins, outs):
    from itertools import izip

    for i, o in izip(ins, outs):
        for a, b in izip(i, o):
            if a in MAPPING:
                continue
            MAPPING[a] = b

train(["ejp mysljylc kd kxveddknmc re jsicpdrysi",
       "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
       "de kr kd eoya kw aej tysr re ujdr lkgc jv"],
      ["our language is impossible to understand",
       "there are twenty six factorial possibilities",
       "so it is okay if you want to just give up"])

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
    return "".join(MAPPING[c] for c in string)
