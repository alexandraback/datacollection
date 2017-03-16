# I apologize to anyone reading this

inputFile = open("D.in")
outputFile = open("D.out", "w")

T = int(inputFile.readline())

for i in range(1, T + 1):
    outputFile.write("Case #" + str(i) + ": ")
    K, C, S = map(int, inputFile.readline().split(" "))
    if C * S < K:
        outputFile.write("IMPOSSIBLE")
    else:
        numbers = []

        for j in range(1, K + 1, C):
            x = 1
            for m in range(0, min(C, K - j)):
                y = j + m
                x += y * K ** (m)
            numbers.append(x)


        outputFile.write(" ".join(map(str, numbers)))

    outputFile.write("\n")
        
