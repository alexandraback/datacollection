from collections import Counter
cases = int(input())

for c in range(cases):
    j, p, s, k = map(int, input().split())

    o = []

    #x1x2 = 0
    #x2x3 = 0
    #x3x1 = 0
    for x1 in range(1, j+1):
    #    x1x2 = 0
    #    x3x1 = 0
        for x2 in range(1, p+1):
    #        x1x2 = 0
    #        x2x3 = 0
            for x3 in range(1, s+1):
    #            x2x3 = 0
    #            x3x1 = 0
                o.append([str(x1), str(x2), str(x3)])
    #            x1x2 += 1
    #            x2x3 += 1
    #            x3x1 += 1
    #            if x2x3 >= k or x3x1 >= k:
    #                continue
    #        if x1x2 >= k or x2x3 >= k:
    #            continue
    #    if x1x2 >= k or x3x1 >= k:
    #        continue

    x1x2 = Counter()
    x2x3 = Counter()
    x3x1 = Counter()

    final = []

    for i in o:
        jp = i[0], i[1]
        ps = i[1], i[2]
        js = i[0], i[2]

        if x1x2[jp] < k and x2x3[ps] < k and x3x1[js] < k:
            x1x2[jp] += 1
            x2x3[ps] += 1
            x3x1[js] += 1
            final.append(" ".join([i[0], i[1], i[2]]))

    print("Case #" + str(c+1) + ":", str(len(final)))
    print("\n".join(final))
