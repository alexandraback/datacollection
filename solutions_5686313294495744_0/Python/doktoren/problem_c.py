'''
cat c_test.in | python problem_c.py
cat C-small-practice.in | python problem_c.py >C-small.out
cat C-large-practice.in | python problem_c.py >C-large.out
'''

from collections import Counter
import sys

def _solve(x_solved, y_solved, pairs):
    if not pairs:
        return 0
    best = 10000
    for i in xrange(len(pairs)):
        x, y = pairs[i]
        x_added, y_added = False, False
        v = int(x not in x_solved or y not in y_solved)
        if x not in x_solved:
            x_solved.add(x)
            x_added = True
        if y not in y_solved:
            y_solved.add(y)
            y_added = True
        v += _solve(x_solved, y_solved, pairs[0:i] + pairs[i+1:])
        if x_added:
            x_solved.remove(x)
        if y_added:
            y_solved.remove(y)
        if v < best:
            best = v
    return best

def _main():
    t = int(sys.stdin.readline().strip())
    for k in xrange(t):
        n = int(sys.stdin.readline().strip())
        pairs = [sys.stdin.readline().strip().split(' ') for i in xrange(n)]
        x_counts = Counter()
        y_counts = Counter()
        for x, y in pairs:
            x_counts[x] += 1
            y_counts[y] += 1
        x_solved = set()
        y_solved = set()
        solution = 0

        progress = True
        while progress:
            progress = False
            for i in xrange(len(pairs)-1, -1, -1):
                x, y = pairs[i]
                if x in x_solved and y in y_solved:
                    x_counts[x] -= 1
                    y_counts[y] -= 1
                    del pairs[i]
                    progress = True
                elif (x not in x_solved and x_counts[x] == 1) or (y not in y_solved and y_counts[y] == 1):
                    x_solved.add(x)
                    y_solved.add(y)
                    solution += 1
                    x_counts[x] -= 1
                    y_counts[y] -= 1
                    del pairs[i]
                    progress = True
                elif x in x_solved and (y not in y_solved and y_counts[y] == 1):
                    y_solved.add(y)
                    solution += 1
                    x_counts[x] -= 1
                    y_counts[y] -= 1
                    del pairs[i]
                    progress = True
                elif (x not in x_solved and x_counts[x] == 1) and y in y_solved:
                    x_solved.add(x)
                    solution += 1
                    x_counts[x] -= 1
                    y_counts[y] -= 1
                    del pairs[i]
                    progress = True

        solution += _solve(x_solved, y_solved, pairs)

        print "Case #{}: {}".format(k+1, n - solution)


def main():
    t = int(sys.stdin.readline().strip())
    for k in xrange(t):
        n = int(sys.stdin.readline().strip())
        pairs = [sys.stdin.readline().strip().split(' ') for i in xrange(n)]
        x_counts = Counter()
        y_counts = Counter()
        for x, y in pairs:
            x_counts[x] += 1
            y_counts[y] += 1
        x_used = set()
        y_used = set()
        solutions = list()

        progress = True
        while progress:
            progress = False
            for i in xrange(len(pairs)-1, -1, -1):
                x, y = pairs[i]
                if x_counts[x] > 1 and y_counts[y] > 1:
                    x_used.add(x)
                    x_counts[x] -= 1
                    y_used.add(y)
                    y_counts[y] -= 1
                    del pairs[i]
                    progress = True
                    solutions.append((x, y))

        progress = True
        while progress:
            progress = False
            for j, pair in enumerate(solutions):
                x, y = pair
                x_counts[x] += 1
                y_counts[y] += 1
                moved = list()
                for i in xrange(len(pairs)):
                    if x_counts[pairs[i][0]] > 1 and y_counts[pairs[i][1]] > 1:
                        moved.append(i)
                if len(moved) > 1:
                    del solutions[j]
                    for i in moved[::-1]:
                        solutions.append(pairs[i])
                        del pairs[i]
                    progress = True
                    break

        print "Case #{}: {}".format(k+1, len(solutions))

main()
