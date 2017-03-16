import os, re, math
 
inf = open('problem4_large.txt', 'r')
 
numproblems = int(inf.readline())
 
outf = open('out4_large.txt', 'w')
 
for problemnum in range(numproblems):
    numblocks = int(inf.readline())
    p1 = inf.readline()
    p1 = re.sub('\n', '', p1)
    p1 = p1.split()
    p1.sort()

    p2 = inf.readline()
    p2 = re.sub('\n', '', p2)
    p2 = p2.split()
    p2.sort()

    origp1 = []
    origp2 = []

    for i in range(numblocks):
        p1[i] = float(p1[i])
        p2[i] = float(p2[i])
        origp1.append(p1[i])
        origp2.append(p2[i])

    # deceitful war
    deceitScore = 0

    for i in range(numblocks):
        # trade lower block for his highest
        if p1[0] < p2[0]:
            p1.remove(p1[0])
            p2.remove(p2[len(p2) - 1])
        # i can lie and win this one
        else:
            p1.remove(p1[0])
            p2.remove(p2[0])
            deceitScore += 1

    # regular war
    regularScore = 0

    p1 = origp1
    p2 = origp2

    origp1.reverse()
    origp2.reverse()

    for i in range(numblocks):
        if origp1[0] > origp2[0]:
            regularScore += 1
            origp1.remove(origp1[0])
            origp2.remove(origp2[len(origp2) - 1])
        else:
            num = len(p1)
            for i in range(num):
                if origp2[num - 1 - i] > origp1[0]:
                    origp1.remove(origp1[0])
                    origp2.remove(origp2[num - 1 - i])
                    break
            

    msg = 'Case #' + str(problemnum + 1) + ': %d %d' % (deceitScore, regularScore)
 
    print msg
    outf.write(msg + '\n')
 
outf.close()
inf.close()
