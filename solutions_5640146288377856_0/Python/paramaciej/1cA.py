#!/usr/bin/env python3

INF = 10**9

T = int(input())

for t in range(1, T + 1):
    r, c, w = (int(x) for x in input().split())

    jest = [0 for x in range(c + 1)]
    nie_ma = [0 for x in range(c + 1)]

    jest[w] = w
    nie_ma[w] = 1

    for i in range(w + 1, c + 1):
        jest[i] = INF
        nie_ma[i] = INF

        for j in range(0, i):
            # print("strzał w j: {}".format(j))
            jest[i] = min(
                jest[i],
                1 + max(
                    w,  # traf, sprawdzam pozostale, raz napotykajac na pudlo
                    max(
                        nie_ma[j] + jest[i - j - 1],
                        jest[j] + nie_ma[i - j - 1]
                    )  # pudlo
                )
            )
            nie_ma[i] = min(
                nie_ma[i],
                1 + max(
                    0,  # traf
                    nie_ma[j] + nie_ma[i - j - 1]  # pudło
                )
            )

    print("Case #{}: {}".format(t, (r - 1) * nie_ma[c] + jest[c]))

