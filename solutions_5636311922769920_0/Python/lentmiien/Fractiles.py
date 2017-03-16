#                      #
#                      #
#  ONLY SMALL DATASET  #
#                      #
#                      #

print("## ONLY SMALL DATASET ##")

# IO files
inputfile = open("D-small-attempt0.in", "r")
#inputfile = open("A-large.in", "r")
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
    if worker < tiles:
        #TODO fix for large dataset (not "IMPOSSIBLE" in all cases)
        print("## ONLY SMALL DATASET ##")
        outputfile.write("Case #" + str(i) + ": IMPOSSIBLE")
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

print("## ONLY SMALL DATASET ##")