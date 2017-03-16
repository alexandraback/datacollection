def solve(n):
    count = 0
    w = [0 for i in xrange(10)]
    x = 0
    while 0 in w:
        count += 1
        if count == 100000: return -1
        x += n
        temp = str(x)
        for c in temp:
            w[int(c)] += 1
    return x

file = open("A-small-attempt0.in", "r")
a = file.readlines()
T = int(a[0])
for i in xrange(1, len(a)):
    temp = solve(int(a[i]))
    print "Case #%d:" % i,
    if (temp == -1): print "INSOMNIA"
    else: print temp
