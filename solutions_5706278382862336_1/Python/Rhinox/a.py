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

import fractions

def ilog2(x):
    n = 0
    while x > 1:
        n += 1
        x /= 2
    return n

def ispow2(x):
    return x > 0 and (x & (x - 1)) == 0

def shorten(p, q):
    frac = fractions.Fraction(p, q)
    return frac.numerator, frac.denominator

def solve(p, q):
    p, q = shorten(p, q)
    if not ispow2(q):
        return None

    return ilog2(q) - ilog2(p)

if __name__ == "__main__":


    fn = "test.txt" if len(sys.argv) <= 1 else sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    def answer(t, ans):
        o = "Case #%d: %s\n"%(t, ans)
        sys.stdout.write(o)
        fout.write(o)

    for case in range(f.int()):
        p, q = map(int, f.line().split("/"))

        ans = solve(p, q)
        if ans is None:
            ans = "impossible"

        answer(case + 1, ans)
