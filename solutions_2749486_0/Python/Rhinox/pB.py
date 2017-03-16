# python 2.7

import os, sys

class Input:
    def __init__(self, fp): self.fp = fp
    def line(self):  return self.fp.readline().strip()
    def words(self): return self.line().split()
    def int(self):   return int(self.line())
    def ints(self):  return map(int, self.words())
    def str(self):   return self.line()
    def types(self, *types): return [t(w) for t,w in zip(types, self.words())]
    def m(self, n):  return [list(self.line()) for i in range(n)]

if __name__ == "__main__":
    fn = sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    def answer(t, ans):
        o = "Case #%d: %s\n"%(t, ans)
        sys.stdout.write(o)
        fout.write(o)

    for T in range(f.int()):
        X, Y = f.ints()
        s = ""

        if X < 0:   s += "EW" * abs(X)
        elif X > 0: s += "WE" * abs(X)
        if Y < 0:   s += "NS" * abs(Y)
        elif Y > 0: s += "SN" * abs(Y)

        answer(T + 1, s)
