import sys


def solve_case(case, J, P, S, K):
    outfits = []
    j_s = {}
    p_s = {}
    j_p = {}
    s = 1
    for j in xrange(1, J + 1):
        for p in xrange(1, P + 1):
            for s in xrange(1, S + 1):
                if j_s.get((j, s), 0) == K or p_s.get((p, s), 0) == K or j_p.get((j, p), 0) == K:
                    continue
                j_s[(j, s)] = j_s.get((j, s), 0) + 1
                p_s[(p, s)] = p_s.get((p, s), 0) + 1
                j_p[(j, p)] = j_p.get((j, p), 0) + 1
                outfits.append([str(j), str(p), str(s)])
    print 'Case #%d: %d' % (case, len(outfits))
    for outfit in outfits:
        print ' '.join(outfit)

if __name__ == '__main__':
    with open(sys.argv[1]) as fd:
        lines = [line.strip() for line in fd.readlines()]
    for i in xrange(1, len(lines)):
        J, P, S, K = [int(number) for number in lines[i].split()]
        solve_case(i, J, P, S, K)
