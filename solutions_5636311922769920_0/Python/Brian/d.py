with open("d.in") as f:
    t = int(next(f))
    for case in xrange(t):
        vals = next(f).split(" ")
        k = int(vals[0])
        c = int(vals[1])
        s = int(vals[2])

        if c*s < k:
            print "Case #{}: IMPOSSIBLE".format(case+1)
            continue

        guesses = []
        level = 0
        index = 0
        pos = 0
        while pos < k:
            index = index * k + pos
            level += 1
            pos += 1
            if level == c:
                guesses.append(index+1)
                level = 0
                index = 0
        if level > 0:
            while level < c:
                index = index * k
                level += 1
            guesses.append(index+1)
        print "Case #{}: {}".format(case+1, " ".join([str(i) for i in guesses]))
            
