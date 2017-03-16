def NLG(inputfile, outputfile):
    print "bezig"
    inputdata = open(inputfile, "r")
    outputdata = open(outputfile, "w")
    T = int(inputdata.readline())
    for case in range(T):
        #read input
        A,B,K = map(int,inputdata.readline().split())
        aantalmogelijkheden = 0
        #probleem
        for i in range(A):
            for j in range(B):
                if j&i < K:
                    aantalmogelijkheden +=1




        outputdata.write("Case #" + str(case+1) + ": " + str(aantalmogelijkheden) + "\n")
    inputdata.close()
    outputdata.close()
    print "done"
