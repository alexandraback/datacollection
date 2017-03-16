import sys


class CounterCulture:
    def __init__(self):
        self.d = [sys.maxint] * (10**6 + 1)
        self.d[0] = 0
        for i in range(1, len(self.d)):
            self.d[i] = min(self.d[i], self.d[i - 1] + 1)
            rev = self.reverse(i)
            if rev <= self.d:
                self.d[rev] = min(self.d[rev], self.d[i] + 1)

    def reverse(self, n):
        return int("".join(reversed(str(n))))

    def solve_case_d(self, n):
        return self.d[n]

    def solve_case(self, f):
        n = int(f.readline())
        return self.solve_case_d(n)

    def create_report(self, ci, r):
        r = ", ".join(map(str, r)) if not isinstance(r, str) and isinstance(r, (list, tuple)) else str(r)
        return "Case #" + str(ci) + ": " + r

    def solve(self, f):
        t = int(f.readline())
        results = []
        for c in range(t):
            results.append(self.solve_case(f))
        return "\n".join(map(lambda c: self.create_report(c[0] + 1, c[1]), enumerate(results)))

    def solve_and_save(self, out, f):
        out.write(self.solve(f))

def run():
    f = open("./in/" + sys.argv[1] + ".in", 'r')
    o = open("./out/" + sys.argv[1] + ".out", 'w')
    cc.solve_and_save(o, f)
    f.close()
    o.close()


if __name__ == "__main__":
    cc = CounterCulture()

    if len(sys.argv) < 2:
        cc.solve_and_save(sys.stdout, sys.stdin)
    else:
        run()