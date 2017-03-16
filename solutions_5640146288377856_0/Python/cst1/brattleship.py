import sys


class Brattleship:

    def solve_case(self, f):
        r, c, w = map(int, f.readline().split())
        return (r - 1) * (c // w) + (c // w + (w - 1) + (c % w > 0))

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

if __name__ == "__main__":
    b = Brattleship()

    if len(sys.argv) < 2:
        b.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        b.solve_and_save(o, f)
        f.close()
        o.close()
