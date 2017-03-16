__author__ = 'sunghyo.jung'

g_c = []
g_j = []
g_min = 99999999999999
g_nv = ""

def track(nv):
    if "?" not in nv:
        global g_min

        l = int(len(nv) / 2)
        c = nv[:l]
        j = nv[l:]
        c_val = int("".join(list(map(str, c))))
        j_val = int("".join(list(map(str, j))))

        if abs(c_val - j_val) < g_min:
            g_min = abs(c_val - j_val)
            global g_nv
            g_nv = nv.copy()
    else:
        idx = 0
        for i in range(len(nv)):
            if nv[i] == "?":
                idx = i
                break
        for i in range(10):
            nv[idx] = i
            track(nv)
            nv[idx] = "?"


for t in range(1, int(input().strip()) + 1):
    c, j = input().strip().split()

    nv = list(c + j)
    track(nv)

    l = int(len(g_nv) / 2)
    nc = g_nv[:l]
    nj = g_nv[l:]
    ans = ("".join(map(str, nc))) + " " + ("".join(map(str, nj)))
    g_min = 999999999999999

    print("Case #%d: %s" % (t, ans))