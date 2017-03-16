infile = open("A-large.in", "rU")
outfile = open("outputA.txt", "w")
linenum = 0
case = 1
for line in infile:
    if linenum != 0:
        line = line.strip()
        listy = line.split(" ")
        scores = []
        for i in xrange(1, len(listy)):
            scores.append(int(listy[i]))
        total = sum(scores)
        string = "Case #" + str(case) + ": "

        scores2 = []
        for s in scores:
            scores2.append(s)
        scores2.sort()
        minimum = scores2[0]
        consider = [minimum]
        count = 0
        for i in xrange(1, len(scores2)):
            if (scores2[i] + count < total) or scores2[i] in consider:
                consider.append(scores2[i])
                count += scores2[i] - minimum
                
        c = 0
        for a in consider:
            c += max(consider) - a
        while c > total:
            consider.remove(consider[-1])
            c = 0
            for a in consider:
                c += max(consider) - a

        for i in xrange(0, len(scores)):
            if scores[i] not in consider:
                string += "0 "
            else:
                rhs = 1
                foundflag = False
                for j in xrange(0, len(consider)):
                    if (consider[j] == scores[i] and foundflag == False):
                        foundFlag = True
                    if (consider[j] != scores[i]) or (consider[j] == scores[i] and foundflag == True):
                        rhs += float(consider[j])/total - float(scores[i])/total
                if case == 17:
                    print rhs, consider
                string += str(float(rhs)/len(consider) * 100) + " "
##        percentages = []
##        for i in xrange(0, len(scores)):
##            rhs = 1
##            for j in xrange(0, len(scores)):
##                if i != j:
##                    rhs += float(scores[j])/total - float(scores[i])/total
##                    if case == 19:
##                        print i, j, rhs
##            prob1 = rhs/len(scores)
##            minimum = scores[i]
##            for j in xrange(0, len(scores)):
##                if i != j and scores[j] < minimum:
##                    minimum = scores[j]
##            prob2 = ((float(scores[i] - minimum)/total) - 1)/(-2)
##            string += str(prob1) + " "
        outfile.write(string + "\n")
        case += 1            
    linenum += 1

outfile.close()
