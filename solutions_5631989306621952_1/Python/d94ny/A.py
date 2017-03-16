t = int(raw_input())

for i in range(t):
    s = raw_input().strip()
    print "Case #{}:".format(i+1),

    f = [s[0]]
    s = s[1:]
    for c in s:
        if c >= f[0]:
            f.insert(0, c)
        else:
            f.append(c)

    print ''.join(f)


