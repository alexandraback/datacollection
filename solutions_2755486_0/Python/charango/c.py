
import itertools

def solve(tribes):
    attacks = []
    for d, n, w, e, s, delta_d, delta_p, delta_s in tribes:
        for i in xrange(n):
            attacks.append((d + i * delta_d, w, e, s + i * delta_s))
            w += delta_p; e += delta_p
    attacks.sort()
    wall, _l, _r = [0] * 2002, 500, 1501
    success = 0
    for day, group in itertools.groupby(attacks, lambda x: x[0]):
        wall_next = wall[:]
        for d, w, e, s in group:
            ok = True
            for i in xrange(w, e + 1):
                l_fail = i > w and wall[i+_l] < s
                r_fail = i < e and wall[i+_r] < s
                if l_fail or r_fail:
                    if i > w: wall_next[i+_l] = max(s, wall_next[i+_l])
                    if i < e: wall_next[i+_r] = max(s, wall_next[i+_r])
                    ok = False
            #print d, w, e, s, ok
            if not ok:
                success += 1
        wall = wall_next
    return success

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        N = int(f.readline())
        tribes = []
        for j in xrange(N):
            tribes.append(map(int, f.readline().split(' ')))
        print 'Case #%d: %d' % (i + 1, solve(tribes))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
