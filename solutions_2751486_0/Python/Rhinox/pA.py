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

    vowels = set("aeiou")

    def getRanges(s, n):
        out = []
        p = 0
        sub = "1" * n
        while True:
            pos = s.find(sub, p)
            if pos < 0: break
            out.append((pos, pos + n))
            p = pos + 1 # + n - 1
        return out

    from bisect import bisect_left as bsl
    for T in range(f.int()):
        name, n = f.types(str, int)
        name = "".join("0" if ch in vowels else "1" for ch in name)
        nlen = len(name)

        d = dict(getRanges(name, n))
        l = sorted(d.keys())
        num = len(l)
        c = 0
        for i in range(nlen):
            j = bsl(l, i)
            if j == num: continue
            b = l[j]
            e = d[b]
            c += 1 + nlen - e

        answer(T + 1, c)
