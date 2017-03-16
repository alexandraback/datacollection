INPUT = "A-small-attempt0.in"
OUTPUT = "A-small-attempt0.out"


def computenum(val):
    if not val:
        return 'INSOMNIA'

    seenDigits = set()
    curVal = val

    while True:
        for c in str(curVal):
            seenDigits.add(c)

        if len(seenDigits) == 10:
            break

        curVal += val

    return str(curVal)


with open(INPUT) as infile:
    with open(OUTPUT, 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            inputVal = int(infile.readline())
            outfile.write("Case #%d: %s\n" % (i + 1, computenum(inputVal)))
