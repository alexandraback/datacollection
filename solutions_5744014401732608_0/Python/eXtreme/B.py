import sys

#f1 = open('/tmp/B-small-attempt0.in')
fin = open('/tmp/in')
sf = sys.stdin


f = sf

if f != sf:
    print 'Warning! Input from file'

tests = int(f.readline())

for tnr in range(1, tests+1):
    B, M = map(int, f.readline().strip().split())

    if M > 2**(B-2):
        print 'Case #%d: IMPOSSIBLE' % tnr
        continue

    # j char of i line == 1 iff i -> j

    E = [[0] * B for _ in range(B)]

    for i in range(0, B-1):
        for j in range(i+1, B-1):
            E[i][j] = 1

    if M == 2**(B-2):
        for i in range(0, B-1):
            E[i][B-1] = 1
    else:
        # Bits 0..B-3 may be lit
        # if bit 0 lit, then slide 1 -> B-1
        # if bit 1 lit, then slide 2 -> B-1
        # if bit B-3 lit, then slide B-2 -> B-1
        for bitnr in range(0, B-2):
            if ((1 << bitnr) & M) != 0:
                E[bitnr + 1][B-1] = 1

    print 'Case #%d: POSSIBLE' % tnr
    for i in range(0, B):
        print ''.join(map(str, E[i]))



