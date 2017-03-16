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
        r, t = f.ints()

        ans = 0
        while True:
            t -= r + r + 1
            if t < 0:
                break
            ans += 1
            r += 2

        answer(T + 1, ans)
