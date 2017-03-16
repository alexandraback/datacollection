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

def find_larger_index(l, index):
    v = l[index]
    for i in range(index + 1, len(l)):
        if l[i] > v: return i
    return -1

def clamp(x, low, high):
    if x < low: return low
    if x > high: return high
    return x

if __name__ == "__main__":
    fn = sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    def answer(t, ans):
        o = "Case #%d: %s\n"%(t, ans)
        sys.stdout.write(o)
        fout.write(o)

    for T in range(f.int()):
        E, R, N = f.ints()
        avs = f.ints()

        e = E
        gain = 0

        for i in range(len(avs) - 1):
            if avs[i] < avs[i + 1]:
                spend = max(e + R - E, 0)
            else:
                j = find_larger_index(avs, i)
                spend = e if (j < 0) else clamp((j - i) * R, 0, e)
            gain += spend * avs[i]
            e = min(E, e - spend + R)

        gain += avs[-1] * e

        answer(T + 1, gain)
