__author__ = 'Sean'

def solve(A, B, K):
    count = 0
    for i in range(A+1):
        for j in range(B+1):
            if i&j < (K+1):
                count += 1
    return count



fileIn = open('B-small.in', 'r')
fileLines = fileIn.readlines()
fileIn.close()

it = iter(fileLines)

numbCases = int(next(it))

output = ""

for case in range(numbCases):
    [A, B, K] = [int(j) for j in next(it).split()]

    output += "Case #{0}: {1}\n".format(case+1, solve(A-1, B-1, K-1))

with open('small.txt', 'w') as fileOut:
    fileOut.write(output)
