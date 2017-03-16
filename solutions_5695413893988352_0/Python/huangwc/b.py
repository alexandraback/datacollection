import sys

sys.stdin = open('B-small-attempt1.in', 'r')
sys.stdout = open('B-small.out', 'w')

for t in range(1, int(input()) + 1):
    a, b = input().strip().split()
    oa = 999
    ob = 0
    diff = None

    ca = sum([1 if c == '?' else 0 for c in a])
    cb = sum([1 if c == '?' else 0 for c in b])

    for x in range(10 ** ca):
        # if diff is not None and diff == 0:
        #     break
        sx = ('000' + str(x))[-ca:]
        for y in range(10 ** cb):
            sy = ('000' + str(y))[-cb:]
            # print(('000' + str(x))[:-3])
            # print(a, b)
            # print(sx, sy)
            pa = list(a)
            pb = list(b)

            ia = 0
            for i in range(len(a)):
                if a[i] == '?':
                    pa[i] = sx[ia]
                    ia += 1

            ib = 0
            for i in range(len(b)):
                if b[i] == '?':
                    pb[i] = sy[ib]
                    ib += 1

            aa = int(''.join(pa))
            bb = int(''.join(pb))
            if diff is None or abs(aa - bb) < diff or abs(
                            aa - bb) == diff and int(oa) > aa:
                diff = abs(aa - bb)
                oa = ''.join(pa)
                ob = ''.join(pb)

    print('Case #%s: %s %s' % (t, oa, ob))
