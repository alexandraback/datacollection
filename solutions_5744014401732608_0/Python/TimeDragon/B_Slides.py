#!python3

inputFile = open("input.txt", "r")
outputFile = open("output.txt", "w")

testCases = int(inputFile.readline())

for testCase in range(1, testCases + 1):

    inp = inputFile.readline()
    inp = inp.rstrip()
    inp = inp.split()
    build = int(inp[0])
    total = int(inp[1])

    print("Case #", testCase, ": ", sep="", end="", file=outputFile)

    mx = 1
    for i in range(1, build - 1):
        mx += (i * (build - 1 - i))

    if mx < total:
        print("IMPOSSIBLE", file=outputFile)
        continue
    else:
        print("POSSIBLE", file=outputFile)

    arr = []
    for i in range(0, build):
        arr.append([0] * build)

    for i in range(0, build - 1):
        arr[i][i + 1] = 1

    #total -= 1
    for i in range(1, build - 1):
        if total == 0:
            break

        if total >= i:
            for j in range(build - i, build):
                #if arr[build - 1 - i][j] == 0:
                #    total -= 1
                arr[build - 1 - i][j] = 1
        else:
            for j in range(build - i, build):
                #if arr[build - 1 - i][j] == 0:
                #    total -= 1
                arr[build - 1 - i][j] = 1
                if total == 0:
                    break

        if total == 0:
            break

        if total >= (i * (build - 1 - i)):
            for j in range(0, build - 1 - i):

                arr[j][build - 1 - i] = 1
            total -= (i * (build - 1 - i))
        else:
            quo = total // i
            for j in range(0, quo):
                arr[j][build - 1 - i] = 1
            total -= (i * quo)

    if total != 0:
        arr[0][build - 1] = 1
        total = 0
    for i in range(0, build):
        for j in range(0, build):
            print(arr[i][j], end="", file=outputFile)
        print(' ', file=outputFile)


inputFile.close()
outputFile.close()
