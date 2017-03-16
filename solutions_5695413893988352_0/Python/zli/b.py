def all_possible(c, j):
    if "?" not in c and "?" not in j:
        yield (c, j)
    elif "?" in c:
        for i in xrange(10):
            for cj in all_possible(c.replace("?", str(i), 1), j):
                yield cj
    elif "?" in j:
        for i in xrange(10):
            for cj in all_possible(c, j.replace("?", str(i), 1)):
                yield cj
    else:
        raise Exception("unknown")

for case in range(1, input()+1):
    print "Case #%s:" % (case),
    scores = raw_input().split()
    prefix = None
    solution = []
    #print scores
    if scores == ["???", "???"]:
        print "000 000"
        continue
    else:
        brute_force = sorted(all_possible(*scores),
                             key=lambda (c,j): (abs(int(c)-int(j)), int(c), int(j)))
        print " ".join(brute_force[0])
        continue
    print "Brute force", brute_force[0]
    direction = None
    for i, cj in enumerate(zip(*scores)):
        cj = "".join(cj)
        #print cj, prefix, direction
        #print solution, i
        if prefix is None:
            if cj == "??":
                solution.append("00")
            elif cj[0] == "?":
                solution.append(cj[1]*2)
            elif cj[1] == "?":
                solution.append(cj[0]*2)
            elif cj[0] != cj[1]:
                solution.append(cj)
                #direction = int(cj[0]) > int(cj[1])
                #prefix = False
                prefix = i
                solution1 = solution[:]
                solution2 = solution[:]
            else:
                solution.append(cj)
        else:
            if cj == "??":
                solution1.append("09")
                solution2.append("90")
            elif cj[0] == "?":
                solution1.append("0"+cj[1])
                solution2.append("9"+cj[1])
            elif cj[1] == "?":
                solution1.append(cj[0]+"9")
                solution2.append(cj[0]+"0")
            else:
                solution1.append(cj)
                solution2.append(cj)
    #for j, cj in enumerate(reversed(prefix)):
    if prefix is None:
        print " ".join("".join(s) for s in zip(*solution))
        continue
    #print prefix, solution, list(enumerate(zip(*scores)))
    bigger = solution[prefix][0] > solution[prefix][1]
    for j in range(prefix-1, -1, -1):
        cj = "".join(zip(*scores)[j])
        #print "iter", j, cj
        if cj == "??":
            if bigger:
                solution2[j] = "01"
            else:
                solution1[j] = "10"
            break
        elif cj[0] == "?":
            if bigger:
                if cj[1] != "0":
                    solution2[j] = "%s%s" % (int(cj[1])-1, cj[1])
                    break
            else:
                if cj[1] != "9":
                    solution1[j] = "%s%s" % (int(cj[1])+1, cj[1])
                    break
        elif cj[1] == "?":
            if not bigger:
                if cj[0] != "0":
                    solution1[j] = "%s%s" % (cj[0], int(cj[0])-1)
                    break
            else:
                if cj[0] != "9":
                    solution2[j] = "%s%s" % (cj[0], int(cj[0])+1)
                    break
    #print "Choose"
    s1s = " ".join("".join(s) for s in zip(*solution1))
    s2s = " ".join("".join(s) for s in zip(*solution2))
    s1 = [int("".join(s)) for s in zip(*solution1)]
    s2 = [int("".join(s)) for s in zip(*solution2)]
    diff1 = abs(s1[0] - s1[1])
    diff2 = abs(s2[0] - s2[1])
    if diff1 == diff2 and s1[0] == s2[0]:
        if s1[1] < s2[1]:
            sol = s1s
        else:
            sol = s2s
    elif diff1 == diff2 and s1[0] < s2[0]:
        sol = s1s
    elif diff1 == diff2 and s1[0] > s2[0]:
        sol = s2s
    elif diff1 < diff2:
        sol = s1s
    elif diff1 > diff2:
        sol = s2s
    else:
        raise Exception("unknown comparison")
    print sol
    print "from %s, %s" % (s1s, s2s)
    assert(sol == " ".join(map(str, brute_force[0])))
    assert(len(s1s) == len(s2s))
    #s1 = " ".join("".join(s) for s in zip(*solution1))
    #s2 = " ".join("".join(s) for s in zip(*solution2))
