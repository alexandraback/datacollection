

def getDigits(num):
    return list(map(int,str(num)))

def solveCase(num):
    num = list(num)
    zeroes = num.count("Z")
    for i in range(zeroes):
        [num.remove(c) for c in "ZERO"]
    
    fours = num.count("U")
    for i in range(fours):
        [num.remove(c) for c in "FOUR"]
    
    twos = num.count("W")
    for i in range(twos):
        [num.remove(c) for c in "TWO"]
    
    fives = num.count("F")
    for i in range(fives):
        [num.remove(c) for c in "FIVE"]
    
    sixes = num.count("X")
    for i in range(sixes):
        [num.remove(c) for c in "SIX"]
    
    threes = num.count("R")
    for i in range(threes):
        [num.remove(c) for c in "THREE"]
    

    ones = num.count("O")
    for i in range(ones):
        [num.remove(c) for c in "ONE"]
    
    sevens = num.count("V")
    for i in range(sevens):
        [num.remove(c) for c in "SEVEN"]
    
    eights = num.count("G")
    for i in range(eights):
        [num.remove(c) for c in "EIGHT"]
    
    nines = num.count("I")
    for i in range(nines):
        [num.remove(c) for c in "NINE"]
    
    return "0" * zeroes + "1" * ones + "2" * twos + "3" *  threes + "4" * fours + "5" * fives + "6" * sixes + "7" * sevens + "8" * eights + "9" * nines




def parseInput(text):
    cases = []
    for i, line in enumerate(text.splitlines()):
        if i == 0:
            continue
        line = line.strip()
        num = str(line)
        cases.append(num)
    return cases


def getCases(filename):
    with open(filename) as h:
        data = h.read()
    return parseInput(data)


def getOutput(solved):
    lines = []
    for i, solvedCase in enumerate(solved):
        lines.append("Case #%d: %s" % (i + 1, solvedCase))
    return '\n'.join(lines)

def generateOutput(filename, outFile = None):
    cases = getCases(filename)
    solvedCases = [solveCase(case) for case in cases]
    output = getOutput(solvedCases)
    if outFile == None:
        outFile = filename[:-2] + "out"
    with open(outFile, "w") as h:
        h.write(output)
    
