inputFile = open("B.in")
outputFile = open("B.out", "w")

s = int(inputFile.readline())



for i in range(s):
    n = 0
    line = inputFile.readline().strip()[::-1]
    if line[0] == "-":
        n = 1

    prevChar = line[0]
    for char in line:
        if char != prevChar:
            n += 1
            prevChar = char
        
    outputFile.write("Case #" + str(i + 1) + ": " + str(n) + "\n")   

