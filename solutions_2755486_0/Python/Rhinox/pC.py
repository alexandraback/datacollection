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

        N = f.int()
        tribes = [f.ints() for i in range(N)]

        days = {}
        for i, t in enumerate(tribes):
            d, n, w, e, s, delta_d, delta_p, delta_s = t
            for j in range(n):
                day = d + j * delta_d
                if day not in days: days[day] = []

                ww = w + j * delta_p
                ee = e + j * delta_p
                ss = s + j * delta_s
                days[day].append((ww, ee, ss))

        offset = 100 + 10*10 + 1
        wall = [0] * 2 * offset

        successful = 0
        for day, attacks in sorted(days.items()):
            rebuild = []
            for attack in attacks:
                w, e, s = attack
                for p in range(w + offset, e + offset):
                    if wall[p] < s:
                        rebuild.append(attack)
                        successful += 1
                        break
            for w, e, s in rebuild:
                for p in range(w + offset, e + offset):
                    wall[p] = s

        answer(T + 1, successful)
