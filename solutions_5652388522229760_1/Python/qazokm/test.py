inputFile = open("test.txt")

t = int(inputFile.readline())

def timeToSleep(n):
    k = n
    if n == 0:
        return -1

    seen = [False] * 10
    numSeen = 0

    while numSeen != 10:
        for digit in list(str(k)):
            if seen[int(digit)] != True:
                seen[int(digit)] = True
                numSeen += 1

        if numSeen != 10:
            k += n

    return k

output = open("out.txt", "w")

for i, line in enumerate(inputFile):
    time = timeToSleep(int(line))

    if time == -1:
        time = "INSOMNIA"

    output.write("Case #" + str(i + 1) + ": " + str(time) + "\n")


