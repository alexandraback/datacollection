t = input()
for i in xrange(t):
    j, p, s, k = map(int, raw_input().split(" "))
    jp_combo = [[0 for x in xrange(p)] for y in xrange(j)]
    ps_combo = [[0 for x in xrange(s)] for y in xrange(p)]
    js_combo = [[0 for x in xrange(s)] for y in xrange(j)]
    jps_combo = [[[0 for x in xrange(s)] for y in xrange(p)] for z in xrange(j)]
    combos = []

    for a in xrange(1, k + 1):
        for b in xrange(1, k + 1):
            for c in xrange(1, k + 1):
                for x in xrange(j):
                    for y in xrange(p):
                        for z in xrange(s):
                            if jp_combo[x][y] < a and ps_combo[y][z] < c and js_combo[x][z] < b and jps_combo[x][y][z] == 0:
                                jp_combo[x][y] += 1
                                ps_combo[y][z] += 1
                                js_combo[x][z] += 1
                                jps_combo[x][y][z] = 1
                                combos.append([x, y, z])


    print "Case #" + str(i + 1) + ":", len(combos)
    for c in combos:
        for a in c:
            print a + 1,
        print