# Need to go to work so this is going to be quick and ugly

import itertools, math

inputFile = open("C.in")
outputFile = open("C.out", "w")

t = int(inputFile.readline())
n, j = map(int, inputFile.readline().split(" "))

found = 0
placeValues = [2 ** i for i in range(1, n - 1)]

def isComposite(k):
    factors = []
    for i in range(2, 11):
        x =  int("{0:b}".format(k), i)
        for j in range(2, min(100, int(math.sqrt(x)) + 1)):
            if x % j == 0:
                factors.append(str(j))
                break
        else:
            return -1

    return factors

outputFile.write("Case #1:\n")

while found < j:
    for i in range(1, n - 2):
        for combination in itertools.combinations(placeValues, i):
            number = sum(combination) + 1 + 2 ** (n - 1)
            composite = isComposite(number)
            if composite != -1:
                outputFile.write("{0:b}".format(number) + " " + str(" ".join(composite)) + "\n")
                found += 1
                if found == j:
                    break

        if found == j:
            break


outputFile.write("\n")

        
