
# IO files
inputfile = open("B-small-attempt0.in", "r")
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
    counter = 0
    pancakes = len(line)
    notdone = 1
    
    while notdone == 1:
        notdone = 0
        for j in range(0, pancakes):
            if line[j] == "-":
                notdone = 1
        if notdone == 1:
            first = line[0]
            smallcnt = 1
            while smallcnt < pancakes:
                if line[smallcnt] != first:
                    break
                else:
                    smallcnt += 1
            counter += 1
            if smallcnt == pancakes:
                line = smallcnt * "+"
            else:
                line = smallcnt * line[smallcnt] + line[smallcnt:]
    
    print("Result: " + str(counter))
    outputfile.write("Case #" + str(i) + ": " + str(counter))
    line = inputfile.readline()

# Close files
outputfile.close()
inputfile.close()