from collections import defaultdict


def compdif(ls):
    if ls == False:
        return 0
    (x1, x2) = ls
    return int(x1) - int(x2)


inputs = int(raw_input())

for qqq in range(inputs):
    inp = raw_input().split(' ')

    hash = {}
    hash = defaultdict(lambda: 0, hash)

    over = ["0", "0"]
    equiv = ["0", "0"]
    under = ["0", "0"]

    for i in range(len(inp[0])):
        best_over = False
        best_equiv = False
        best_under = False

        overb = 0
        underb = 0

        overt1 = 0
        undert1 = 0


        c0 = inp[0][i]
        c1 = inp[1][i]

        if c0 == "?":
            r0 = range(10)
        else:
            r0 = [int(c0)]

        if c1 == "?":
            r1 = range(10)
        else:
            r1 = [int(c1)]

        for d0 in r0:
            for d1 in r1:
                tries = []
                if over != False:
                    tries.append(over)
                if equiv != False:
                    tries.append(equiv)
                if under != False:
                    tries.append(under)
                for att in tries:
                    att0 = int(att[0]) * 10 + d0
                    att1 = int(att[1]) * 10 + d1

                    att0s = att[0] + str(d0)
                    att1s = att[1] + str(d1)

                    if att0 < att1:
                        if best_under == False:
                            best_under = [att0s, att1s]
                        else:
                            newdiff = att0 - att1
                            olddiff = compdif(best_under)

                            if newdiff > olddiff:
                                best_under = [att0s, att1s]
                            elif newdiff == olddiff:
                                if att0 < int(best_under[0]) or (att0 == int(best_under[0]) and att1 < best_under[1]):
                                    best_under = [att0s, att1s]

                    if att0 == att1:
                        if best_equiv == False:
                            best_equiv = [att0s, att1s]
                        else:
                            if att0 < int(best_equiv[0]):
                                best_equiv = [att0s, att1s]

                    if att0 > att1:
                        #print "hi: " + att0s + " " + att1s
                        if best_over == False:
                            best_over = [att0s, att1s]
                        else:
                            newdiff = att0 - att1
                            olddiff = compdif(best_over)

                            if newdiff < olddiff:
                                best_over = [att0s, att1s]
                            elif newdiff == olddiff:
                                if att0 < int(best_over[0]) or (att0 == int(best_over[0]) and att1 < best_over[1]):
                                    best_over = [att0s, att1s]

        over = best_over
        under = best_under
        equiv = best_equiv

        #print best_over
        #print best_under
        #print best_equiv

    overval = abs(compdif(over))
    underval = abs(compdif(under))
    equivval = abs(compdif(equiv))

    best = over
    bestval = overval



    if (underval < bestval and under != False) or best == False:
        best = under
        bestval = underval
    if underval == bestval and under != False:
        if int(under[0]) < int(best[0]) or (int(under[0]) == int(best[0]) and int(under[1]) < int(best[1])):
            best = under
            bestval = underval

    if (equivval < bestval and equiv != False) or best == False:
        best = equiv
        bestval = equivval

    if equivval == bestval and equiv != False:
        if int(equiv[0]) < int(best[0]) or (int(equiv[0]) == int(best[0]) and int(equiv[1]) < int(equiv[1])):
            best = equiv
            bestval = equivval

    ans0 = best[0][1:]
    ans1 = best[1][1:]

    print "Case #" + str(qqq+1) + ": " + ans0 + " " + ans1
    
    
