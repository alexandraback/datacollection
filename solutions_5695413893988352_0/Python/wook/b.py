import sys
rl = lambda: sys.stdin.readline().strip()

from itertools import product

def go(L, R):
    L = list(L)
    R = list(R)
    pos =  [(1, i) for i in xrange(len(L)) if L[i] == '?']
    pos += [(0, i) for i in xrange(len(R)) if R[i] == '?']

    best = 1e100
    best_assign = None, None
    for g in product(*(['0123456789'] * len(pos))):
        #print pos, g, L, R
        for (is_l, i), assign in zip(pos, g):
            if is_l: L[i] = assign
            else: R[i] = assign
        #print pos, g, L, R

        l_score = ("".join(L))
        r_score = ("".join(R))
        score_diff = abs(int(l_score) - int(r_score))
        if best > score_diff:
            best = score_diff
            best_assign = l_score, r_score

    return best_assign


def main():
    T = int(rl())
    for kase in xrange(1, T+1):
        L, R = rl().split()
        x, y = go(L, R)
        print "Case #%d: %s %s" % (kase, x, y)

if __name__ == '__main__':
    main()
