#!/usr/bin/env python
import sys

def solve(size, n, motes):
    if size == 1:
        # can never eat anything
        return n
    motes.sort()
    print motes
    for i, m in enumerate(motes):
        if m < size:
            size += m
        else:
            break
    else:
        # could eat everything
        return 0

    # couldn't eat everything
    best = (n - i)
    j = i
    need_to_add = 0
    print j, best
    while j < n:
        while size <= motes[j]:
            # we need more motes, better make them as big as possible
            size += (size - 1)
            need_to_add += 1
        while motes[j] < size:
            # we're now large enough to eat stuff
            size += motes[j]
            j += 1
            if j == n: break
        score = need_to_add + (n - j)
        print j, score
        if score < best:
            best = score
    return best

if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            print "Case #{0}:".format(case)

            a, n = map(int,fin.readline().split())
            motes = map(int, fin.readline().split())

            soln = solve(a, n, motes)
            print soln
            print >> fout, "Case #{0}: {1}".format(case, soln)
