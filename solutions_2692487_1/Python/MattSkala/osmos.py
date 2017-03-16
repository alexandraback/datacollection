from math import *

filename = "A-large"

def count_fixes(armin, motes, operation):
    fixes = 0
    motes = list(motes)
    while True:
        if len(motes) == 0:
            break
        elif armin > motes[0]:
            armin += motes[0]
            motes.pop(0)
        else:
            if (operation == 'add'):
                motes.insert(0, armin - 1)
            else:
                motes.pop(-1)
            fixes += 1

    return fixes

def solve(armin, motes):
    motes = sorted(motes, key=int)
    fixes = 0

    while True:
        if len(motes) == 0: # Finished
            break
        elif armin > motes[0]: # We can eat
            armin += motes[0]
            motes.pop(0)
        elif armin == 1: # If we are too small, it is impossible to eat someone
            motes.pop(-1)
            fixes += 1
        elif count_fixes(armin, motes, 'add') < count_fixes(armin, motes, 'remove'):
            motes.insert(0, armin - 1)
            fixes += 1
        else:
            motes.pop(-1)
            fixes += 1

    return fixes

fi = open(filename + ".in", "r")
fo = open(filename + ".out", "w")

cases = int(fi.readline())

for case in range(cases):
    line = fi.readline().replace("\n", "")
    armin, motesCount = [int(num) for num in line.split(" ")]
    motesLine = fi.readline().replace("\n", "")
    motes = []
    [motes.append(int(mote)) for mote in motesLine.split(" ")]

    result = solve(armin, motes)
    output = "Case #%d: %s" % (case + 1, result)
    print(output)
    fo.write(output + "\n")

fi.close()
fo.close()