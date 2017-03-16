

import sys
from collections import Counter


def debug(s):
    print >> sys.stderr, s


def valid(groups, solution):
    sets = []

    def get_letters(s):
        ret = set()
        for i in s:
            ret.update(set(i))
        return ret

    sets = map(get_letters, groups)
#    debug(sets)
#    debug(groups)
    for i in xrange(len(sets)):
        for j in xrange(len(sets)):
            if i != j and sets[i] & sets[j]:
                return False

    used = set()
    for s in solution:
        last = None
        for i in s:
            if last != i and i in used:
                return False
            last = i
            used.add(last)

    return True


def compute(group, ends):
    ret = 1
    sets = Counter()
    for item in group:
        if item[0] == item[-1]:
            sets[item[0]] += 1
    for v in sets.values():
        ret *= factorial(v)
    return ret


def factorial(n):
    ret = 1
    for i in xrange(1, n + 1):
        ret *= i
        ret = ret % 1000000007
    return ret


def solve(f, t):
    _ = int(f.readline())
    s = f.readline().strip().split()
    ends = []
    groups = []
    solution = []

    def merge_sets(start, end, item=None):
        tmp = groups[end]
        groups[start].extend(tmp)
        if item:
            groups[start].append(item)
        ends[start] = ends[start][0], ends[end][1]
        ends.pop(end)
        groups.pop(end)

    def merge_groups(groups, solution, ends):
        merged = True
        while merged:
            merged = False
            for i in xrange(len(groups)):
                for j in xrange(len(groups)):
                    if i != j:
                        if ends[i][0] == ends[j][1]:
                            merge_sets(j, i)
                            merged = True
                        if ends[i][1] == ends[j][0]:
                            merge_sets(i, j)
                            merged = True

    for item in s:
        first, last = item[0], item[-1]
        end = start = -1
        for index, (gfirst, glast) in enumerate(ends):
            if first == glast:
                start = index
                continue
            if last == gfirst:
                end = index
                continue
        #print start, end, groups, ends, solution, item
        if start != -1 and end != -1:
            merge_sets(start, end, item)
            solution[start] = solution[start] + item + solution[end]
            solution.pop(end)
        elif start != -1:
            groups[start].append(item)
            ends[start] = ends[start][0], last
            solution[start] = solution[start] + item
        elif end != -1:
            groups[end].append(item)
            ends[end] = first, ends[end][1]
            solution[end] = item + solution[end]
        else:
            groups.append([item])
            ends.append((first, last))
            solution.append(item)

    merge_groups(groups, solution, ends)
    debug(ends)
    debug(groups)
    if not valid(groups, solution):
        return 0
    ret = 1
    for i in xrange(len(groups)):
        ret *= compute(groups[i], ends[i])
        ret = ret % 1000000007
    ret *= factorial(len(groups))
    return ret

if __name__ == "__main__":
    f = sys.stdin
    T = int(f.readline())
    for _t in xrange(T):
        ret = solve(f, _t)
        print 'Case #%s: %s' % (_t + 1, ret)
