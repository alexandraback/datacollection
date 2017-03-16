t = int(raw_input())

for it in range(1, t + 1):
    out = 0
    num = int(raw_input())
    tmp = num
    if num == 0:
        out = 'INSOMNIA'
    else:
        digits = set(list(str(tmp)))
        while len(digits) < 10:
            tmp += num
            digits |= set(list(str(tmp)))
        out = tmp
    print "Case #{}: {}".format(it, out)
