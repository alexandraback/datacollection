data = open("a_in.txt", "r").readlines()
data = map(lambda x: int(x.rstrip()), data)
n, data = data[0], data[1:]

fout = open("a_out.txt", "wb")
for case, m in enumerate(data):
    ans = None
    if m == 0:
        ans = "INSOMNIA"
    else:
        digit, ans = set(), m
        while True:
            ds = list(str(ans))
            digit = digit.union(set(ds))
            #print digit
            if len(digit) == 10:
                break
            ans += m
    out = "Case #%s: %s" % (case + 1, ans)
    fout.write("%s\n" % out)
