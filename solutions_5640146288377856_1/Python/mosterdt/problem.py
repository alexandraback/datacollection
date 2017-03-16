import time
def brattleship(inputfile, outputfile):
    print "bezig"
    start_tijd = time.time()
    inputdata = open(inputfile, "r")
    outputdata = open(outputfile, "w")
    T = int(inputdata.readline())
    for case in range(T):
        #read input
        R,C,W = map(int,inputdata.readline().split())

        moves = min(R*(C/W) + W, R*(C/W) + C%W + W-1)





        outputdata.write("Case #" + str(case+1) + ": " + str(moves) + "\n")
    inputdata.close()
    outputdata.close()
    print "done", time.time()-start_tijd

brattleship("input.txt","output.txt")
brattleship("Ab0.in","Ab0.out")
