# IO files
#inputfile = open("D-small-attempt0.in", "r")
inputfile = open("D-large.in", "r")
outputfile = open("output.txt", "w")

# Test cases
line = inputfile.readline()
cases = int(line) + 1
line = inputfile.readline()

# Solve the cases
for i in range(1, cases):
    if i > 1:
        outputfile.write("\n")
    souji = line.find("\n")
    if souji != -1:
        line = line[0:-1]
    print(line)
    
    # Find values
    space = line.find(" ")
    tiles = int(line[0:space])
    line = line[space+1:]
    space = line.find(" ")
    complexity = int(line[0:space])
    worker = int(line[space+1:])
    
    #Solve problem
    if worker < tiles - complexity + 1:
        # impossible
        print("Result: Impossible")
        outputfile.write("Case #" + str(i) + ": IMPOSSIBLE")
    elif worker < tiles:
        # possible
        print("Result:", end="")
        outputfile.write("Case #" + str(i) + ":")
        controlCnt = 0
        for j in range(0, worker):
            myChoice = 0
            for k in range(0, complexity):
                myChoice *= tiles
                myChoice += controlCnt
                if controlCnt < (tiles - 1):
                    controlCnt += 1
            myChoice += 1
            print(" " + str(myChoice), end="")
            outputfile.write(" " + str(myChoice))
            if controlCnt == (tiles - 1):
                print(" ")
                break
    else:
        print("Result: " + str(1), end="")
        outputfile.write("Case #" + str(i) + ": " + str(1))
        for j in range(1, worker):
            nexttile = (j*(tiles ** (complexity-1)))+1
            print(" " + str(nexttile), end="")
            outputfile.write(" " + str(nexttile))
        print(" ")
    line = inputfile.readline()

# Close files
outputfile.close()
inputfile.close()