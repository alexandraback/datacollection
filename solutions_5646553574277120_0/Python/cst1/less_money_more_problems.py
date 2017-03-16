import sys


class LessMoneyMoreProblems:

    def solve_case(self, f):
        c, d, v = map(int, f.readline().split())
        coins = set(map(int, f.readline().split()))

        max_v = 0
        while max_v < v:
            max_v = 0
            try:
                for coin in sorted(coins):
                    for n in xrange(1, c + 1):
                        for i in xrange(max_v + 1):
                            option = i + n * coin
                            if option > max_v + 1:
                                candidate = 1
                                while candidate in coins:
                                    candidate += 1
                                coins.add(candidate)
                                raise Exception()
                            elif option == max_v + 1:
                                max_v += 1
                                if max_v == v:
                                    # print coins, len(coins) - d
                                    return len(coins) - d
                if max_v < v:
                    coins.add(max(coins) + 1)
            except Exception:
                continue
        return len(coins) - d

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
    lmmp = LessMoneyMoreProblems()

    if len(sys.argv) < 2:
        lmmp.solve_and_save(sys.stdout, sys.stdin)
    else:
        f = open("./in/" + sys.argv[1] + ".in", 'r')
        o = open("./out/" + sys.argv[1] + ".out", 'w')
        lmmp.solve_and_save(o, f)
        f.close()
        o.close()
