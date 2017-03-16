m = input()
for test in range(m):
    n = input()
    if n == 0:
        print "Case #" + str(test + 1) + ": " + "INSOMNIA"
        continue
    x = n
    d = set()

    for i in str(x):
        d.add(i)

    while len(d) < 10:
        x += n
        for i in str(x):
            d.add(i)

    print "Case #" + str(test + 1) + ": " + str(x)

