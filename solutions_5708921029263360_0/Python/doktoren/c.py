import sys
import random

random.seed()

def find_problem(solution, constraints, k):
    for p in constraints:
        if len(solution & p) > k:
            return p
    return None

def main():
    t = int(sys.stdin.readline().strip())
    for kk in xrange(t):
        j, p, s, k = [int(s) for s in sys.stdin.readline().strip().split(' ')]
        all_triples = {(xj, xp, xs) for xj in xrange(j) for xp in xrange(p) for xs in xrange(s)}
        constraints = ([{(xj, xp, xs) for xs in xrange(s)} for xj in xrange(j) for xp in xrange(p)] +
                       [{(xj, xp, xs) for xp in xrange(p)} for xj in xrange(j) for xs in xrange(s)] +
                       [{(xj, xp, xs) for xj in xrange(j)} for xp in xrange(p) for xs in xrange(s)])

        pool = list()
        for _ in xrange(16):
            solution = set(all_triples)
            problem = find_problem(solution, constraints, k)
            while problem:
                solution.remove(random.choice(list(solution & problem)))
                problem = find_problem(solution, constraints, k)
            pool.append(solution)

        pool2 = list()
        for i in xrange(len(pool)):
            for j in xrange(i):
                solution = pool[j] | pool[i]
                problem = find_problem(solution, constraints, k)
                while problem:
                    solution.remove(random.choice(list(solution & problem)))
                    problem = find_problem(solution, constraints, k)
                pool2.append(solution)

        best = None
        for i in xrange(len(pool2)):
            for j in xrange(i):
                solution = pool2[j] | pool2[i]
                problem = find_problem(solution, constraints, k)
                while problem:
                    solution.remove(random.choice(list(solution & problem)))
                    problem = find_problem(solution, constraints, k)
                if best is None or len(solution) > len(best):
                    best = solution

        print "Case #{}: {}".format(kk+1, len(best))
        for day in solution:
            print "{} {} {}".format(day[0]+1, day[1]+1, day[2]+1)

main()
