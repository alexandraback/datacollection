__author__ = 'Sean'

def solve(P, Q):
    leftover = Q
    while leftover % 2 == 0:
        leftover = leftover // 2

    if P % leftover > 0:
        return -1
    else:
        redP = P // leftover
        redQ = Q // leftover

        while redP % 2 == 0 and redQ % 2 == 0:
            redP = redP // 2
            redQ = redQ // 2

        if redQ == 1 and redP == 0:
            return -1
        elif redQ == 1:
            return 0

        count = 0
        while not redQ == 1:
            if redQ <= 2 * redP:
                count += 1
                break
            redP *= 2
            while redP % 2 == 0 and redQ % 2 == 0:
                redP = redP // 2
                redQ = redQ // 2
            count += 1

        return count


fileIn = open('A-small.in', 'r')
fileLines = fileIn.readlines()
fileIn.close()

it = iter(fileLines)

numbCases = int(next(it))

output = ""

for case in range(numbCases):
    [P, Q] = [int(j) for j in next(it).split('/')]
    answer = solve(P, Q)

    if answer == -1:
        answer = "impossible"

    output += "Case #{0}: {1}\n".format(case + 1, answer)

with open('small.txt', 'w') as fileOut:
    fileOut.write(output)
