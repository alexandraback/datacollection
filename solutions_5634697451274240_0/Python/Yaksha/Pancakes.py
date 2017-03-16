FILENAME = "B-small-attempt0"

def numFlips(stack, inverse=False):
    happy = '-' if inverse else '+'

    # base case
    if not stack:
        return 0

    (stack, lastChar) = (stack[:-1], stack[-1])
    if lastChar == happy:
        return numFlips(stack)
    else:
        return numFlips(stack, inverse=(not inverse)) + 1


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