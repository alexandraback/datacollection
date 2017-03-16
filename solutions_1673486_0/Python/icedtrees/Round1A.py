file = open("C:\CodeJam\\Round1AAsmall.in","r")
output = open("C:\CodeJam\\Round1AAsmall.txt","w")

cases = int(file.readline())

for case in range(1,cases+1):
    alreadyTyped, total = list(map(int,file.readline().strip().split()))
    probabilities = list(map(float,file.readline().strip().split()))

    lowest = 2 + total


    multiplicativeSum = 1
    for index in range(len(probabilities) + 1):
        if index > 0:
            multiplicativeSum *= probabilities[index - 1]
        expected = 1 + (total - index) + (alreadyTyped - index) + ((1 - multiplicativeSum) * (1 + total))
        lowest = min(lowest,expected)
    output.write("Case #" + str(case) + ": " + str(lowest))
    if case != cases:
        output.write("\n")

file.close()
output.close()