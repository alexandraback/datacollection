inp = open("D-large.in.txt", 'r')
out = open("large_output.txt", 'w')
ncase = int(inp.readline())

for cidx in range(ncase):
    info = inp.readline()
    info_list = info.rstrip().split()
    if len(info_list) == 0:
        continue
    k = int(info_list[0])
    c = int(info_list[1])
    s = int(info_list[2])

    p = k**c

    if c == 1:
        need = k
        start = 1
    else:
        if k == 1:
            need = 1
        else:
            need = k-1
        start = k

    if s < need:
        out.write("Case #" + str(cidx + 1) + ": IMPOSSIBLE\n")
    else:
        need = max(need, s)
        end = start + need
        if end > p:
            diff = end - p
            start = start - diff
            if start < 1:
                start = 1
        out.write("Case #" + str(cidx + 1) + ": " + ' '.join([str(i) for i in range(start, end)]) + '\n')
