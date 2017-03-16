# coding: utf-8

import sys

def solve(P):
    max_p = max(P)
    min_minutes = max_p
    for with_max in range(1, max_p):
        n_cuts = 0
        for Pi in P:
            n_cuts += (Pi - 1) / with_max
        minutes = n_cuts + with_max
        if min_minutes > minutes:
            min_minutes = minutes
    return min_minutes

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        D = int(fp.readline())
        P = map(int, fp.readline().strip().split(' '))
        result = solve(P)
        print 'Case #{}: {}'.format(t + 1, result)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            main(f)
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
