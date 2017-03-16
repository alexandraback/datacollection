import sys
sys.setrecursionlimit(200000)

class Solver():
    def __init__(self, line):
        while "++" in line:
            line = line.replace("++", "+")
        while "--" in line:
            line = line.replace("--", "-")
        line = tuple(c == "+" for c in line)
        self.line = line
        self.lookup = dict()
        self.visited = set()
    def solve(self):
        best = self._solve(self.line)
        return best
    def flip(self, line, idx):
        k = tuple(list(not c for c in reversed(line[:idx])) + list(line[idx:]))
        kk = []
        for l in k:
            if not kk or kk[-1] is not l:
                kk.append(l)
        return tuple(kk)
    def _solve(self, line, depth = 0):
        if line in self.lookup:
            return self.lookup[line]
        if line in self.visited:
            return 1000000000000000000
        if not line:
            return 0
        if False not in line:
            return 0
        if True not in line:
            return 1

        self.visited.add(line)
        best = 10000000000000000
        for flip in xrange(0, len(line)):
            if line[flip] is line[0]:
                continue
            newline = self.flip(line, flip)
            cost = 1 + self._solve(newline, depth + 1)
            best = min(best, cost)
        self.lookup[line] = best
        return best


if __name__ == "__main__":
    f = open("D.in")

    lines = f.read().splitlines()
    interp_line = lambda x: map(int, x.split(" "))
    for idx, line in enumerate(lines[1:]):
        solver = Solver(line)
        print "Case #%d: %d" % (1+idx, solver.solve())

    f.close()
