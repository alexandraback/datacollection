inputFile = open("A.in")
outputFile = open("A.out", "w")

T = int(inputFile.readline())

for i in range(T):
    S = inputFile.readline().strip()
    winningWord = S[0]

    for j in range(1, len(S)):
        if winningWord[0] <= S[j]:
            winningWord = S[j] + winningWord

        else:
            winningWord = winningWord + S[j]

    outputFile.write("Case #" + str(i + 1) + ": " + winningWord + "\n")

inputFile.close()
outputFile.close()

