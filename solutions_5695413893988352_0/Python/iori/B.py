#!/usr/bin/env python3

T = int(input())
for t in range(1, T+1):
    ans = ''
    a, b = input().split()

    if len(a) == 1:
        if a[0] == '?' and b[0] == '?':
            ans = '0 0'
        elif a[0] == '?':
            ans = '{} {}'.format(b[0], b[0])
        elif b[0] == '?':
            ans = '{} {}'.format(a[0], a[0])
        else:
            ans = '{} {}'.format(a[0], b[0])
    elif len(a) == 2:
        dist = float('inf')
        candidate = []
        for ai in range(0, 100):
            flaga = True
            for aa1, aa2 in zip('{:02}'.format(ai), a):
                if aa2 == '?':
                    continue
                elif aa1 != aa2:
                    flaga = False
                    break
            if flaga is False:
                continue
            for bi in range(0, 100):
                flagb = True
                for aa1, aa2 in zip('{:02}'.format(bi), b):
                    # if ai == 5:
                    #     print('{:02}'.format(bi), b)
                    #     print(aa1, aa2)
                    if aa2 == '?':
                        continue
                    elif aa1 != aa2:
                        flagb = False
                        break
                if flagb is False:
                    continue
                if abs(ai-bi) <= dist:
                    dist = abs(ai-bi)
                    candidate.append([dist, ai, bi])
        cand = []
        for c in candidate:
            if c[0] != dist:
                continue
            cand.append([c[0], c[1], c[2]])
        ans = "{:02} {:02}".format(cand[0][1], cand[0][2])
        # candidate = []
        # for c in cand:
        #     if c[0] != cand[0][0]:
        #         continue
        #     candidate.append(c)
        # print(candidate)
    else:
        dist = float('inf')
        candidate = []
        for ai in range(0, 1000):
            flaga = True
            for aa1, aa2 in zip('{:03}'.format(ai), a):
                if aa2 == '?':
                    continue
                elif aa1 != aa2:
                    flaga = False
                    break
            if flaga is False:
                continue
            for bi in range(0, 1000):
                flagb = True
                for aa1, aa2 in zip('{:03}'.format(bi), b):
                    # if ai == 5:
                    #     print('{:03}'.format(bi), b)
                    #     print(aa1, aa2)
                    if aa2 == '?':
                        continue
                    elif aa1 != aa2:
                        flagb = False
                        break
                if flagb is False:
                    continue
                if abs(ai-bi) <= dist:
                    dist = abs(ai-bi)
                    candidate.append([dist, ai, bi])
        cand = []
        for c in candidate:
            if c[0] != dist:
                continue
            cand.append([c[0], c[1], c[2]])
        ans = "{:03} {:03}".format(cand[0][1], cand[0][2])
    print("Case #{}: {}".format(t, ans))
