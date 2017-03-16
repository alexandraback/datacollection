import codejam
import numpy

def check_line(lines, N, M, maxH, maxV):
    for i in xrange(N):
        for j in xrange(M):
            if lines[i][j] < maxH[i] and lines[i][j] < maxV[j]:
                return False

    return True


for case in xrange(codejam.readint()):
    N, M = codejam.readintarray()
    lines = [map(int, codejam.readstring().split()) for l in xrange(N)]

    maxH = [max(l) for l in lines]
    maxV = [max(lines[i][j] for i in xrange(N)) \
                for j in xrange(M)]

    valid = check_line(lines, N, M, maxH, maxV)
    print "Case #%d: %s" % (case + 1, "YES" if valid else "NO")
