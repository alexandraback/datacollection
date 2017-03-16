# triplets.py
from collections import defaultdict
from sys import stdin

isNormal = lambda x: max(x) - min(x) < 2
isSurprising = lambda x: max(x) - min(x) == 2

triplets = [[a,b,c] for a in range(11) for b in range(min(a+3, 11)) for c in range(min(a+3, 11))]

#normalsums - max -> set(sum) (for normals
normSums = defaultdict(lambda:-1)
for s in filter(isNormal, triplets):
    normSums[sum(s)] = max(s)
surpSums = defaultdict(lambda:-1)
for s in filter(isSurprising, triplets):
    surpSums[sum(s)] = max(s)

#solution = defaultdict(lambda:-1)
def recurse(target, solution, sums, at, left):
    if at == len(sums):
        assert(left == 0)
        return 0
    idx = at * 100 + left
    if solution[idx] == -1:
        solution[idx] = 0
        # normal sum, can take if not forced to surprise
        if len(sums)-at > left:
            solution[idx] = recurse(target, solution, sums, at+1, left)
            # :) Can take from normal sum
            if target <= normSums[sums[at]]:
                solution[idx] += 1
        if left:
            if target <= surpSums[sums[at]]:
                solution[idx] = max(solution[idx],
                               1 + recurse(target, solution, sums, at+1, left-1))
            else:
                solution[idx] = max(solution[idx],
                                    recurse(target, solution, sums, at+1, left-1))
    # print at, sums[at], solution[idx]
    return solution[idx]

def main():
    cases = int(stdin.readline())
    for case in range(1, cases+1):
        ls = [int(x) for x in stdin.readline().split()]
        N, S, P = ls[:3]
        sums = ls[3:]
        result = recurse(P, defaultdict(lambda:-1), sums, 0, S)
        print 'Case #%d: %d' % (case, result)

if __name__ == "__main__":
    main()
