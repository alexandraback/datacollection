import sys
import os
import bisect
from collections import deque


def problem_specific_parser(src):
    nblocks = next(src)
    naomi = [float(e) for e in next(src).split(" ")]
    ken = [float(e) for e in next(src).split(" ")]

    return naomi, ken


def optimal(data):
    score = 0
    naomi = data[0].copy()
    naomi.sort()
    ken = data[1].copy()
    ken.sort()
    for e in naomi:
        idx = bisect.bisect(ken, e)
        if idx == len(ken):
            score += len(ken)
            break
        del(ken[idx])
    return score

def deceitful(data):
    score = 0
    naomi = data[0].copy()
    naomi.sort()
    ken = data[1].copy()
    ken.sort()
    ken = deque(ken)

    for e in naomi:
        idx = bisect.bisect(ken, e)
        if idx == 0:
            ken.pop()
            continue
        if idx == len(ken):
            score += len(ken)
            break
        if ken[0] < e:
            ken.popleft()
            score += 1

    return score

def solve(data):
    return  "{0} {1}".format(deceitful(data), optimal(data))


def parse(src):
    lines = iter(src.split(os.linesep))
    nproblems = int(next(lines))

    for problem in range(nproblems):
        yield problem_specific_parser(lines)


def main():
    src = sys.stdin.read()
    for i, data in enumerate(parse(src)):
        print("Case #{0}: {1}".format(i + 1, solve(data)))

    
if __name__ == '__main__':
    main()
