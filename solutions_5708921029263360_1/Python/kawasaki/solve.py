import itertools

T = int(raw_input())
for tc in xrange(1, T + 1):
    J, P, S, K = map(int, raw_input().split())

    maxoutfits = None
    maxoutfits_size = 0

    for dj in xrange(J):
        for dp in xrange(P):
            for ds in xrange(S):
                CNT = 0
                outfits = {(0, 0, 0)}
                jp, js, ps = {(0, 0): 1}, {(0, 0): 1}, {(0, 0): 1}
                j = p = s = 0
                while True:
                    j, p, s = (j + dj) % J, (p + dp) % P, (s + ds) % S
                    if jp.get((j, p), 0) >= K or js.get((j, s), 0) >= K or ps.get((p, s), 0) >= K or (j, p, s) in outfits:
                        CNT += 1
                        if CNT == 10000:
                            break
                        if CNT % (P * S) == 0:
                            j = (j + 1) % J
                        elif CNT % S == 0:
                            p = (p + 1) % P
                        else:
                            s = (s + 1) % S
                        continue
                    outfits.add((j, p, s))
                    jp[(j, p)] = jp[(j, p)] + 1 if (j, p) in jp else 1
                    js[(j, s)] = js[(j, s)] + 1 if (j, s) in js else 1
                    ps[(p, s)] = ps[(p, s)] + 1 if (p, s) in ps else 1
                if maxoutfits_size < len(outfits):
                    maxoutfits_size = len(outfits)
                    maxoutfits = outfits

    print 'Case #{}: {}'.format(tc, len(maxoutfits))
    for j, p, s in maxoutfits:
        print j + 1, p + 1, s + 1
