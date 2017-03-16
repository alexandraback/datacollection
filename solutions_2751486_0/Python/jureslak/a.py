def has3(i, j, name, n):
#    print "Does", name[i:j+1], "have", n, "?",
    z = 0
    for c in name[i:j+1]:
        if z == n: return True
        if c in "aeiou":
            z = 0
        else:
            z += 1
    return z == n

t = int(raw_input())
for c in range(t):
    name, n = raw_input().split()
    n = int(n)

    r = 0
    for i in range(len(name)):
        for j in range(i+n-1, len(name)):
            if has3(i, j, name, n):
                r += 1
#                print "yes"

    print "Case #{}: {}".format(c+1, r)
