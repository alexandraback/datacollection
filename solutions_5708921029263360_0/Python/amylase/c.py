from collections import defaultdict


def solve():
    a, b, c, k = map(int, raw_input().strip().split())
    anstup = []
    bc = defaultdict(int)
    for _i in range(a):
        ccnt = defaultdict(int)
        for _j in range(b):
            i = _i + 1
            j = _j + 1
            cnts = [(bc[(_j, _k)], _k) for _k in range(c) if bc[(_j, _k)] < k and ccnt[_k] < k]
            cnts.sort()
            for cnt, _k in cnts[:k]:
                kk = _k + 1
                anstup.append((i, j, kk))
                bc[(_j, _k)] += 1
                ccnt[_k] += 1
    ab, bc, ca = defaultdict(int), defaultdict(int), defaultdict(int)
    for x, y, z in anstup:
        ab[(x,y)] += 1
        bc[(y, z)] += 1
        ca[(z, x)] += 1

    assert max(ab.values()) <= k
    assert max(bc.values()) <= k
    assert max(ca.values()) <= k
    assert len(anstup) == len(set(anstup))
    print len(anstup)
    for t in anstup:
        print ' '.join(map(str, t))


if __name__ == '__main__':
    n = int(raw_input())
    for i in range(n):
        print "Case #{}:".format(i+1),
        solve()