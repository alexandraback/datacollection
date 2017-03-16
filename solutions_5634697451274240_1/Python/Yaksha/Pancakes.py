FILENAME = "B-large"

def numFlipsIt(stack):
    numChanges = 0

    for i in range(len(stack)-1):
        if stack[i] != stack[i+1]:
            numChanges += 1

    if stack[-1] == '-':
        numChanges += 1

    return numChanges

with open(FILENAME + ".in") as infile:
    with open(FILENAME + ".out", 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            inputVal = infile.readline().strip()
            outfile.write("Case #%d: %s\n" % (i + 1, numFlipsIt(inputVal)))

