#!/usr/bin/python3.4

best = {1: 1}
new = [1]

T = int(input())
for c in range(1, T + 1):
    n = int(input())
    while (not (n in best)):
        newnew = []
        for num in new:
            if ((num + 1) in best):
                if (best[num] + 1 < best[num + 1]):
                    best[num + 1] = best[num] + 1
                    newnew.append(num + 1)
            else:
                best[num + 1] = best[num] + 1
                newnew.append(num + 1)
            rev = int(str(num)[::-1])
            if (rev in best):
                if (best[num] + 1 < best[rev]):
                    best[rev] = best[num] + 1
                    newnew.append(rev)
            else:
                best[rev] = best[num] + 1
                newnew.append(rev)
            new = newnew
    print("Case #%d: %d" % (c, best[n]))
