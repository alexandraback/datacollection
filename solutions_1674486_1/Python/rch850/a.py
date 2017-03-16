import sys

sys.setrecursionlimit(1024)

def main():
    T = int(raw_input())
    for tid in xrange(T):
        N = int(raw_input())
        M = []
        for n in xrange(N):
            M.append([int(x) - 1 for x in raw_input().split()][1:])
        class Overlap(Exception):
            pass
        def step(b, pos):
            if b[pos] != 0:
                raise Overlap()
            b[pos] = 1
            for mi in M[pos]:
                step(b, mi)
        try:
            for i in xrange(N):
                step([0] * N, i)
        except Overlap:
            print "Case #%d: Yes" % (tid + 1)
        else:
            print "Case #%d: No" % (tid + 1)

main()

