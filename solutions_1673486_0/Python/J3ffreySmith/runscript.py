def partA(infile="C:/Users/Jeffrey/Dropbox/Google Code Jam/2011/Round 1A/A/input.txt",\
              outfile="C:/Users/Jeffrey/Dropbox/Google Code Jam/2011/Round 1A/A/output.txt"):
    
    #Reading input
    linesA = []
    for line in open(infile, 'r'):
        linesA.append(line.strip())

    outA = []
        
    #Parsing Input
    T = int(linesA[0])
    for i in range(1, 1 + T * 2,2):
        caseA = linesA[i].split()
        A = int(caseA[0])
        B = int(caseA[1])
        P = linesA[i+1].split()
        
        CP = 1
        LE = []
        for j in range(A):
            #print (A-j), CP, float(P[j])
            LE.append(CP * (A - j + B - j + 1) + (1 - CP) * (A + 2 * (B - j) + 2))
            CP = CP * (float(P[j]))
        LE.append(CP * (B - A + 1) + (1 - CP) * (2 * B - A + 2))
        LE.append(B + 2)
        
        outA.append("Case #" + str((i-1)/2 + 1) + ": " + "%.6f" % min(LE))
        
        #print CP, LE, P
        
        
    out = open(outfile, 'w')
    print "\nOUTPUT"
    for i in range(1, 1 + T):
        if i != 1:
            out.write("\n")
        print outA[i-1]
        out.write(outA[i-1])
    out.close()