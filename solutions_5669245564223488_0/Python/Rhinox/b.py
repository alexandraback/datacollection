# python 2.7

import os, sys

class Input:
    def __init__(self, fp): self.fp = fp
    def m(self, n, t=str):  return [map(t, list(self.line())) for i in range(n)]
    def ms(self, n, t=str, sep=' '):  return [map(t, self.line().split(sep)) for i in range(n)]
    def line(self):  return self.fp.readline().strip()
    def lines(self, n): return [self.fp.readline().strip() for x in range(n)]
    def words(self): return self.line().split()
    def int(self):   return int(self.line())
    def ints(self):  return map(int, self.words())
    def float(self): return float(self.line())
    def floats(self):return map(float, self.words())
    def str(self):   return self.line()
    def types(self, *types): return [t(w) for t,w in zip(types, self.words())]

class Id:
    def __init__(self):
        self.n = 0
        self.d = {}
    def __call__(self, o):
        if o in self.d:
            return self.d[o]
        self.n += 1
        self.d[o] = self.n
        return self.n

from itertools import groupby, permutations
def rle(s):
    return [(v, sum(1 for x in g)) for (v, g) in groupby(s)]

import math
from collections import Counter

def verify(ll):
    q = 0
    s = set()
    for l in ll:
        for e in l:
            if e == q: continue
            q = e
            if e in s: return False
            s.add(e)
    return True

if __name__ == "__main__":
    fn = "test.txt" if len(sys.argv) <= 1 else sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    mod = 1000000007

    def answer(t, ans):
        o = "Case #%d: %s\n"%(t, ans)
        sys.stdout.write(o)
        fout.write(o)

    toid = Id()
    for case in range(f.int()):
        N = f.int()
        old = f.words()
        old = ["".join(ch for (ch, c) in rle(s)) for s in old]

        sets = []
        counter = Counter()
        for o in old:
            if o not in counter:
                sets.append(o)
            counter.update((o,))

        mult = 1
        for k in counter:
            mult *= math.factorial(counter[k])

        # Convert to int
        for i in range(len(sets)):
            sets[i] = tuple(toid(ch) for ch in list(sets[i]))

        #print "mult:", mult

        n = 0
        for perm in permutations(sets):
            if verify(perm):
                n += 1

        ans = (n * mult) % mod
        answer(case + 1, ans)
