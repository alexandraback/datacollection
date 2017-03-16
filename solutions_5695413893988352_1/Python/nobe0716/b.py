__author__ = 'sunghyo.jung'

import sys
sys.setrecursionlimit(100)

g_c = []
g_j = []
g_min = 999999999999999999
g_nv = ""


def get_winner(c, j):
    for c_elem, j_elem in zip(c, j):
        if c_elem == "?" or j_elem == "?":
            return None
        elif int(c_elem) > int(j_elem):
            return "c"
        elif int(c_elem) < int(j_elem):
            return "j"
    return None


def track(c, j, winner):
    if "?" not in c and "?" not in j:
        global g_min

        c_val = int("".join(list(map(str, c))))
        j_val = int("".join(list(map(str, j))))

        new_min = abs(c_val - j_val)
        if new_min < g_min:
            g_min = new_min
            global g_c
            global g_j
            g_c = c.copy()
            g_j = j.copy()

    else:
        c_idx = -1
        j_idx = -1
        for i in range(len(c)):
            if c[i] == "?" and j[i] == "?":
                j_idx = c_idx = i
                break
            elif c[i] == "?":
                c_idx = i
                break
            elif j[i] == "?":
                j_idx = i
                break

        if winner is None:
            new_winner = get_winner(c, j)
            if new_winner is not None:
                track(c, j, new_winner)
            else: # new_winner is None
                if c_idx >= 0 and j_idx >= 0: # both "?"
                    c[c_idx] = 0
                    j[j_idx] = 0
                    track(c, j, None)
                    c[c_idx] = 0
                    j[j_idx] = 1
                    track(c, j, "j")
                    c[c_idx] = 1
                    j[j_idx] = 0
                    track(c, j, "c")

                    c[c_idx] = j[j_idx] = "?"
                elif c_idx >= 0:
                    if int(j[c_idx]) > 0:
                        c[c_idx] = int(j[c_idx]) - 1
                        track(c, j, "j")

                    c[c_idx] = j[c_idx]
                    track(c, j, None)

                    if int(j[c_idx]) < 9:
                        c[c_idx] = int(j[c_idx]) + 1
                        track(c, j, "c")
                    c[c_idx] = "?"

                elif j_idx >= 0:
                    if int(c[j_idx]) > 0:
                        j[j_idx] = int(c[j_idx]) - 1
                        track(c, j, "c")

                    j[j_idx] = c[j_idx]
                    track(c, j, None)

                    if int(c[j_idx]) < 9:
                        j[j_idx] = int(c[j_idx]) + 1
                        track(c, j, "j")
                    j[j_idx] = "?"
        elif winner is "c":
            if c_idx >= 0 and j_idx >= 0: # both "?"
                c[c_idx] = 0
                j[j_idx] = 9
                track(c, j, winner)
                c[c_idx] = j[j_idx] = "?"
            elif c_idx >= 0:
                c[c_idx] = 0
                track(c, j, winner)
                c[c_idx] = "?"
            elif j_idx >= 0:
                j[j_idx] = 9
                track(c, j, winner)
                j[j_idx] = "?"
        elif winner is "j":
            if c_idx >= 0 and j_idx >= 0: # both "?"
                c[c_idx] = 9
                j[j_idx] = 0
                track(c, j, winner)
                c[c_idx] = j[j_idx] = "?"
            elif c_idx >= 0:
                c[c_idx] = 9
                track(c, j, winner)
                c[c_idx] = "?"
            elif j_idx >= 0:
                j[j_idx] = 0
                track(c, j, winner)
                j[j_idx] = "?"

for t in range(1, int(input().strip()) + 1):
    c, j = [list(x) for x in input().strip().split()]
    winner = get_winner(c, j)
    track(c, j, winner)

    l = int(len(g_nv) / 2)
    nc = g_c
    nj = g_j
    ans = ("".join(map(str, nc))) + " " + ("".join(map(str, nj)))
    g_min = 999999999999999999

    print("Case #%d: %s" % (t, ans))