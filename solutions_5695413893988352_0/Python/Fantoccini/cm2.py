from multiprocessing import Pool
from collections import defaultdict
import math
import traceback, sys

def wrap(line):
    try:
        return solve(line)
    except:
        raise Exception("".join(traceback.format_exception(*sys.exc_info())))

def solve(line):
    c, j = line.strip().split(" ")
    n = len(c)
    max = 1000
    min = None
    res = ""
    if n == 1:
        max = 10
    if n == 2:
        max = 100
    for nc in xrange(max):
        for nj in xrange(max):
            nnc = str(nc).zfill(n)
            nnj = str(nj).zfill(n)
            match = True
            for i in xrange(n):
                if c[i] != "?" and c[i] != nnc[i]:
                    match = False
                if j[i] != "?" and j[i] != nnj[i]:
                    match = False
            if match:
                mmm = math.fabs(nc - nj)
                if min == None or mmm < min:
                    min = mmm
                    res = nnc + " "+ nnj
    print res
    return res



p = Pool(8)
with open("in.txt", "r") as fin:
    results = p.map(wrap, fin.readlines()[1:])
    with open("out1.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res)))
