# -*- encoding: utf8 -*-
import itertools


def solve(s):
    # Get all subset.
    subsets = []
    for i in range(1, len(s) + 1):
        subsets += list(itertools.combinations(s, i))
    subsets_sum = []
    for s in subsets:
        subsets_sum.append(sum(s))
    for i in range(len(subsets_sum)):
        for j in range(len(subsets_sum)):
            if i == j:
                continue
            if subsets_sum[i] == subsets_sum[j]:
                return (
                    ' '.join(map(str, subsets[i]))
                    +
                    '\n'
                    +
                    ' '.join(map(str, subsets[j]))
                )
    return 'Impossible'


def main():
    t = int(raw_input())
    for i in range(t):
        tmp = map(int, raw_input().split())
        n, s = tmp[0], tmp[1:]
        print 'Case #%d:' % (i + 1)
        print solve(s)





if __name__ == '__main__':
    main()
