t = int(raw_input())
for c in range(t):
    name, n = raw_input().split()
    n = int(n)

    r = 0
    s = ''
    g = 0
    cg = 0
    ilg = -1
    for i in range(len(name)):
        if name[i] in "aeiou":
            r += (ilg+1)
            cg = 0
        else:
            cg += 1
            if cg >= n:
                g += 1
                r += (i-n+2)
                ilg = i-n+1
            else:
                r += (ilg+1)
        s += name[i]

    print "Case #{}: {}".format(c+1, r)
