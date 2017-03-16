#!/usr/local/bin/python
import sys

def count_stars(levels):
    return sum(x[2] for x in levels)

def complete_stage1(levels, stars):
    potentials = []
    for i, level in enumerate(levels):
        if level[0] <= stars and level[2] == 0:
            potentials.append((i, level))

    if potentials:
        print "can do", potentials
        i, todo = max(potentials, key=lambda (i, level): level[1])
        print "completing stage 1 on", todo
        levels[i] = todo[0], todo[1], 1
        return True
    return False

def complete_stage2(levels, stars, complete):
    new_complete = 0
    print levels
    while complete < len(levels) and levels[complete][1] <= stars:
        stars += 2 - levels[complete][2]
        levels[complete] = levels[complete][0], levels[complete][1], 2
        complete += 1
        new_complete += 1
    return new_complete, stars

def solve(N, levels):
    levels = sorted(levels, key=lambda x: x[1])
    levels = [(a, b, 0) for a, b in levels]
    print levels
    stars = 0
    complete = 0 # number of completed stage2's
    attempts = 0 # the number of times a level has been completed
    while stars < 2 * N:
        new_complete, stars = complete_stage2(levels, stars, complete)
        complete += new_complete
        success = complete_stage1(levels, stars)
        new_complete += success
        if new_complete == 0:
            return "Too Bad"
        stars += success
        attempts += new_complete
    return attempts


if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in range(1, T+1):
            print "case", case
            N = int(fin.readline())
            levels = [tuple(map(int, fin.readline().split())) for i in range(N)]
            soln = solve(N, levels)
            print >> fout, "Case #{0}: {1}".format(case, soln)
