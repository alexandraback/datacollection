T = int(raw_input())


for case in xrange(1, T+1):
    J, P, S, K = map(int, raw_input().split())

    outfits = []
    seenij = {}
    seenik = {}
    seenjk = {}

    for i in xrange(J):
        for j in xrange(P):
            for k in xrange(S):
                if seenij.get((i, j), 0) == K:
                    continue
                elif seenik.get((i, k), 0) == K:
                    continue
                elif seenjk.get((j, k), 0) == K:
                    continue

                outfits.append((i+1, j+1, k+1))
                seenij[(i, j)] = seenij.get((i, j), 0) + 1
                seenik[(i, k)] = seenik.get((i, k), 0) + 1
                seenjk[(j, k)] = seenjk.get((j, k), 0) + 1

    print 'Case #{}: {}'.format(case, len(outfits))
    for outfit in outfits:
        print ' '.join(map(str, outfit))
