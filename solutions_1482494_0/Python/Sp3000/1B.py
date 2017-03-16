infile = open("B-small-attempt0.in", "rU")
outfile = open("outputB.txt", "w")

linenum = 0
nfound = False
case = 0
for line in infile:
    if linenum != 0:
        line = line.strip()
        if nfound == False:
            nfound = True
            N = int(line)
            count = 0
            level = [0]*N
            star1 = [0]*N
            star2 = [0]*N
        else:
            listy = line.split(" ")
            star1[count] = int(listy[0])
            star2[count] = int(listy[1])
            count += 1
            if count == N:
                nfound = False
                case += 1

                #Check if solution is possible
                solution = True
                maxs = max(star2)
                strip = [0]*(maxs+1)
                for s in star1:
                    strip[s] += 1
                for s in star2:
                    strip[s] += 1
                totalstars = 0
                for pos in xrange(0, len(strip)):
                    if totalstars < pos:
                        solution = False
                        outfile.write("Case #{0}: Too Bad\n".format(case))
                        break
                    totalstars += strip[pos]

                if solution:
                    starsgot = 0
                    moves = 0
                    while starsgot != N*2:
                        for l in xrange(0, N):
                            if star2[l] <= starsgot and level[l] == 0:
                                starsgot += 2
                                level[l] = 2
                                moves += 1
                                print starsgot, moves, l
                                break
                        else:
                            for l in xrange(0, N):
                                if star2[l] <= starsgot and level[l] == 1:
                                    level[l] = 2
                                    starsgot += 1
                                    moves += 1
                                    print starsgot, moves, l
                                    break
                            else:
                                startwolist = []
                                posslist = []
                                for l in xrange(0, N):
                                    if star1[l] <= starsgot and level[l] == 0:
                                        startwolist.append(star2[l])
                                        posslist.append(l)
                                m = max(startwolist)
                                level[posslist[startwolist.index(m)]] += 1
                                starsgot += 1
                                moves += 1
                                print starsgot, moves, 
                    outfile.write("Case #{0}: {1}\n".format(case, moves))
                            

    linenum += 1

outfile.close()
