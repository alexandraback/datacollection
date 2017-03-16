#!python3

inputFile = open("input.txt", "r")
outputFile = open("output.txt", "w")

testCases = int(inputFile.readline())

for i in range(0, testCases):
    startValue = inputFile.readline()
    startValue = startValue[:-1]
    result = startValue[0]

    for a in range(1, len(startValue)):
        if startValue[a] < result[0]:
            result += startValue[a]
        else:
            result = startValue[a] + result
    print("Case #", i + 1, ": ", result, sep="", file=outputFile)
