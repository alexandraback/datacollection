import sys
for t in range(int(input().strip())):
    c, d = input().strip().split()
    coder = ""
    jammer = ""
    l = len(c)
    min_diff = sys.maxsize
    min_c = ""
    min_j = ""
    if c[0] == '?':
        start_i = 0
    else:
        start_i = int(c[0]) * (10 ** (l - 1))
    if d[0] == '?':
        start_j = 0
    else:
        start_j = int(d[0]) * (10 ** (l - 1))

    for i in range(start_i, 10**l):
        for j in range(start_j, 10**l):
            ok = True
            i_string = (("0" * l) + str(i))[-l:]
            j_string = (("0" * l) + str(j))[-l:]
            for m in range(l):
                if c[m] != '?' and c[m] != i_string[m]:
                    ok = False
                    break
            if ok:
                for n in range(l):
                    if d[n] != '?' and d[n] != j_string[n]:
                        ok = False
                        break
            if ok:
                if abs(i - j) < min_diff:
                    min_diff = abs(i - j)
                    min_c = i_string
                    min_j = j_string
            if min_diff == 0:
                break
        if min_diff == 0:
            break
    print("Case #%d: %s %s" % (t + 1, min_c, min_j))
