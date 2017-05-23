#!python3

inputFile = open("input.txt", "r")
outputFile = open("output.txt", "w")

testCases = int(inputFile.readline())

for i in range(0, testCases):
    height = [0] * 2502
    ListN = int(inputFile.readline())
    for j in range(0, (2*ListN - 1)):
        ListC = inputFile.readline().split()
        for k in range(0, ListN):
            inp = int(ListC[k])
            height[inp] += 1

    print("Case #", i + 1, ": ", sep="", end="", file=outputFile)
    for j in range(1, 2501):
        if height[j] % 2:
            print(j, end=" ", file=outputFile)
    print("", file=outputFile)