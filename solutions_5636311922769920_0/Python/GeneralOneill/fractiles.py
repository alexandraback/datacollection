def fractile(k, c):
    out = []
    l = pow(k, c)
    p = 0
    index = 1
    while True:
        l /= k
        index += l * p
        p += 1
        if l == 1:
            out.append(index)
            l = pow(k, c)
            index = 1
            if p == k:
                break
        if p == k:
            p -= 1
    return out
cases = int(raw_input())
for case in range(cases):
    line_in = raw_input().split()
    k = int(line_in[0])
    c = int(line_in[1])
    n = int(line_in[2])
    out = fractile(k, c)
    out = map(str, out)
    line_out = ""
    if(n < len(out)):
        line_out = "IMPOSSIBLE"
    else:
        line_out = " ".join(out)
    print("Case #" + str(case+1) + ": " + line_out)
