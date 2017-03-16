class Level(object):
    def __init__(self, a1, a2):
        self.a1 = a1
        self.a2 = a2
        self.earned = 0

def solve(problem):
    steps, points = 0, 0
    levels = sorted((Level(*lvl) for lvl in problem), key=lambda lvl: (lvl.a2, -lvl.a1))
    while levels:
        steps += 1
        level = levels[0]
        if points >= level.a2:
            points += 2 - level.earned
            levels.pop(0)
            continue
        candidates = [lvl for lvl in levels if lvl.a1 <= points and lvl.earned == 0]
        if not candidates:
            return "Too Bad"
        lvl = candidates[-1]
        lvl.earned = 1
        points += 1
    return steps

def problems(fin):
    N = int(fin.next())
    for _ in xrange(N):
        line = fin.next()
        n = int(line)
        problem = [map(int, fin.next().split(" ")) for _ in xrange(n)]
        yield problem

def main():
    with open("problem_2_large.in") as fin:
        with open("problem_2_large.out", "w") as fout:
            for i, problem in enumerate(problems(fin)):
                ans = solve(problem)
                ans = "Case #{0}: {1}\n".format(i + 1, ans)
                print ans,
                fout.write(ans)

if __name__ == "__main__":
    main()
