# Solution to "Dijkstra" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

quat = {("1", "1"): ( 1, "1"), ("1", "i"): ( 1, "i"), ("1", "j"): ( 1, "j"), ("1", "k"): ( 1, "k"),
        ("i", "1"): ( 1, "i"), ("i", "i"): (-1, "1"), ("i", "j"): ( 1, "k"), ("i", "k"): (-1, "j"),
        ("j", "1"): ( 1, "j"), ("j", "i"): (-1, "k"), ("j", "j"): (-1, "1"), ("j", "k"): ( 1, "i"),
        ("k", "1"): ( 1, "k"), ("k", "i"): ( 1, "j"), ("k", "j"): (-1, "i"), ("k", "k"): (-1, "1")}  

savedblocksign, savedblock = 1, "i"

def calcblock(string):
    global savedblocksign, savedblock
    cursign, current = 1, "1"
    for d in string:
        nextsign, current = quat[(current, d)]
        cursign *= nextsign
    savedblocksign, savedblock = cursign, current

def findi(l, x, string):
    cursign, current = 1, "1"
    found = {}
    for n, d in enumerate(string):
        nextsign, current = quat[(current, d)]
        cursign *= nextsign
        test = (cursign, current)
        if test not in found:
            found[test] = n
    if (1, "i") in found:
        return (0, found[(1, "i")])
    blocksign, block = cursign, current
    baseblocksign, baseblock = blocksign, block 
    for blockNum in xrange(1, min(x, 5)):
        newfound = {}
        for (sign, val), pos in found.items():
            nextsign, nextval = quat[(block, val)]
            nextsign *= blocksign*sign
            if (nextsign, nextval) == (1, "i"):
                return (blockNum, pos)
            newfound[(nextsign, nextval)] = pos
        nextsign, block = quat[(block, baseblock)]
        blocksign *= nextsign*baseblocksign
    return (-1, -1)

def findk(l, x, string):
    cursign, current = 1, "1"
    found = {}
    for n, d in enumerate(reversed(string)):
        nextsign, current = quat[(d, current)]
        cursign *= nextsign
        test = (cursign, current)
        if test not in found:
            found[test] = n
    if (1, "k") in found:
        return (0, found[(1, "k")])
    blocksign, block = cursign, current
    baseblocksign, baseblock = blocksign, block 
    for blockNum in xrange(1, min(x, 5)):
        newfound = {}
        for (sign, val), pos in found.items():
            nextsign, nextval = quat[(val, block)]
            nextsign *= blocksign*sign
            if (nextsign, nextval) == (1, "k"):
                return (blockNum, pos)
            newfound[(nextsign, nextval)] = pos
        nextsign, block = quat[(baseblock, block)]
        blocksign *= nextsign*baseblocksign
    return (-1, -1)

def calcmiddle(sblock, s, eblock, e, string):
    if sblock > eblock:
        return "NO"
    if sblock == eblock and s > e:
        return "NO"
    cursign, current = 1, "1"
    if sblock == eblock:
        for c in string[s:e+1]:
            nextsign, current = quat[(current, c)]
            cursign *= nextsign
    else:
        for c in string[s:]:
            nextsign, current = quat[(current, c)]
            cursign *= nextsign
        for m in range((eblock - sblock - 1)%4):
            nextsign, current = quat[(current, savedblock)]
            cursign *= nextsign*savedblocksign
        for c in string[:e+1]:
            nextsign, current = quat[(current, c)]
            cursign *= nextsign
    if (cursign, current) == (1, "j"):
        return "YES"
    else:
        return "NO"

def solve(l, x, string):
    calcblock(string)
    iblock, ipos = findi(l, x, string)
    kblock, kpos = findk(l, x, string)
    if iblock == -1 or kblock == -1:
        return "NO"
    if kpos == len(string) - 1:
        midend = len(string) - 1
        midendblock = x - 2 - kblock
    else:
        midend = len(string) - 2 - kpos
        midendblock = x - 1 - kblock
    if ipos == len(string) - 1:
        midstart = 0
        midstartblock = iblock + 1
    else:
        midstart = ipos + 1
        midstartblock = iblock
    return calcmiddle(midstartblock, midstart, midendblock, midend, string)


def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            l, x = (int(x) for x in infile.readline().split())
            yield l, x, infile.readline().rstrip()

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
