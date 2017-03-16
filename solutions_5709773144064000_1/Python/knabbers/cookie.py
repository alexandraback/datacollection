def solve(file):
    f = open(file,'r')
    lines = f.readlines()
    nCases = int(lines[0])
    outf = open("output.txt",'w')
    i = 1 # line number
    n = 1 # case number
    while nCases > 0:
        print("case: " + str(n))
        line = lines[i].replace('\n', "").split(" ")
        C = float(line[0])
        F = float(line[1])
        X = float(line[2])

        tprev = X/2 # time with no factories
        t = 0
        nfactories = 0
        partsum = 0
        while True:
            nfactories += 1
            partsum += 1/( (nfactories-1)*F+2 )
            t = partsum*C + X/( nfactories*F+2 )
            if (t > tprev):
                break
            tprev = t

        outf.write("Case #" + str(n) +": " + str(tprev) + "\n")

        i += 1
        nCases -= 1
        n+=1

    f.close()
    outf.close()
