infile = open("A-small-attempt0.in", "rU")
outfile = open("outputA.txt", "w")

linenum = 0
case = 1
Nfound = False
for line in infile:
    if linenum != 0:
        if Nfound == False:
            Nfound = True
            line = line.strip()
            N = int(line)
            count = 0
            inherit = [[]]
        else:
            count += 1
            line = line.strip()
            listy = line.split(" ")
            extend = []
            for index in xrange(1, len(listy)):
                extend.append(int(listy[index]))
            inherit.append(extend)
            if count == N:
                diamond = False
                Nfound = False
                for index in xrange(1, len(inherit)):
                    if inherit[index] == [] and diamond == False:
                        floodlist = [index]
                        foundlist = []
                        change = True
                        while change == True:
                            change = False
                            for i in xrange(1, len(inherit)):
                                for num in floodlist:
                                    if num in inherit[i] and [num, i] not in foundlist:
                                        if i in floodlist:
                                            diamond = True
                                            break
                                        else:
                                            foundlist.append([num, i])
                                            floodlist.append(i)
                                            change = True
                                            break
                if diamond:
                    outfile.write("Case #" + str(case) + ": Yes\n")
                else:
                    outfile.write("Case #" + str(case) + ": No\n")
                case += 1
        
    linenum += 1
outfile.close()
