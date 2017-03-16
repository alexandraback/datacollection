DEFN = 16
DEFJ = 50

# e.g. base 10, only multiples of 3, 7, 9, 11, etc. can result in numbers ending in "1"
def generateDivisors(base):
    cap = 1000  # Don't go down rabbit hole of large divisions

    if base == 2:
        return (x for x in range(2, cap) if x % 2)
    elif base == 3:
        return (x for x in range(2, cap) if x % 3)
    elif base == 4:
        return (x for x in range(2, cap) if x % 2)
    elif base == 5:
        return (x for x in range(2, cap) if x % 5)
    elif base == 6:
        return (x for x in range(2, cap) if (x % 6) in [5, 1])
    elif base == 7:
        return (x for x in range(2, cap) if x % 7)
    elif base == 8:
        return (x for x in range(2, cap) if x % 2)
    elif base == 9:
        return (x for x in range(2, cap) if x % 3)
    elif base == 10:
        return (x for x in range(2, cap) if (x % 10) in [1, 3, 7, 9])


def findFactor(val, base):
    for i in generateDivisors(base):
        if not (val % i):
            return i


def generateCandidates(n):
    # generates strings of length n that consists of only '1' and '0', and start and end with '1'
    candidate = "1" + "0" * (n - 2) + "1"
    candidateAsNum = int(candidate, 2)
    while True:
        yield(candidate)
        candidateAsNum += 2
        candidate = "{0:b}".format(candidateAsNum)


print("Case #1:")
numFound = 0
for candidate in generateCandidates(DEFN):
    output = candidate + " "

    for base in range(2, 11):
        factor = findFactor(int(candidate, base), base)
        if not factor:
            break

        output += "%d " % factor

    else:
        print(output)
        numFound += 1
        if numFound == DEFJ:
            break



