Q = "?"
cached = {}
def getDigits(num):
    return list(map(int,str(num)))

def solveCase(nums, reverseSol = False, lastWasQ = False):
    cName = (tuple(nums), reverseSol, lastWasQ)
    if cName in cached:
        return cached[cName]
    res = solveCaseC(nums, reverseSol, lastWasQ)
    cached[cName] = res
    return res

def solveCaseC(nums, reverseSol = False, lastWasQ = False):

    g1, g2 = nums
    onums = nums
    if g1 == "" and g2 == "":
        return ("", "")
    g1 = list(g1)
    g2 = list(g2)
    n1 = ""
    n2 = ""
    nums = []
    cases = []
    # if g1 > g2, then we need to maximize all from the right on g2, minimize all on g1
    for (i, (d1, d2)) in (list(enumerate(zip(g1, g2)))):

        if "?" in [d1, d2]:
            break
        
    if g1[:i] != g2[:i]:
        g1 = ''.join(g1)
        g2 = ''.join(g2)
        if int(g1[:i]) > int(g2[:i]):
            return (tryMinimize(g1), tryMaximize(g2))
        else:
            return (tryMaximize(g1), tryMinimize(g2))
    
    if i == len(g1) - 1 and "?" not in [d1, d2]:

        return onums
    prefix = g1[:i]
    g1 = g1[i:]
    g2 = g2[i:]
    # ? N, N ?, ? ?
    fopts = []
    if (d1, d2) == ("?", "?"):
        
        fopts = []
        dopts = ["0", "9", "1"]
        dopts1 = dopts
        dopts2 = dopts
        if lastWasQ is not False and len(g1) > 1 and g1[1] == "?" and g2[1] == "?":
            dopts1 = [lastWasQ[0]]
            dopts2 = [lastWasQ[1]]
            
        for opt1 in dopts1:
            for opt2 in dopts2:
                curr1 = [opt1] + g1[1:]
                curr2 = [opt2] + g2[1:]
                fopts.append(solveCase((''.join(prefix + curr1), ''.join(prefix + curr2)), lastWasQ = (opt1, opt2)))
    elif d2 == "?":
        return solveCase((''.join(prefix + g2), ''.join(prefix + g1)), True)

    elif d1 == "?":
        d2i = int(d2)
        fopts = []
        opts = list(set([str((d2i+1)%10), str((d2i-1)%10), d2, "0", "9"]))
        for opt in opts:
            curr = [opt] + g1[1:]
            fopts.append(solveCase((''.join(prefix + curr), ''.join(prefix + g2))))

            

    res = []
    bMatch = (None, float("inf"))
    for num1, num2 in fopts:
        if reverseSol:
            num2, num1 = num1, num2
        d = abs(int(num1)-int(num2))
        doSwap = False
        if d == bMatch[1]:
            oldC, oldJ = int(bMatch[0][0]), int(bMatch[0][1])
            newC, newJ = int(num1), int(num2)
            if newC < oldC:
                doSwap = True
            elif newC == oldC:
                if newJ < oldJ:
                    doSwap = True
            
        if d < bMatch[1]:
            doSwap = True
        if doSwap:
            bMatch = ((num1, num2), d)
            
    return bMatch[0]
        
    


def tryMaximize(num):
    if type(num) == list:
        num = str(num)
    digits = ["9"] * num.count("?")
    return (num.replace("?", "9"))

def tryMinimize(num):
    if type(num) == list:
        num = str(num)
    digits = ["0"] * num.count("?")
    return (num.replace("?", "0"))

def parseInput(text):
    cases = []
    for i, line in enumerate(text.splitlines()):
        if i == 0:
            continue
        line = line.strip()
        num = tuple(str(line).split(" "))
        cases.append(num)
    return cases


def getCases(filename):
    with open(filename) as h:
        data = h.read()
    return parseInput(data)


def getOutput(solved):
    lines = []
    for i, solvedCase in enumerate(solved):
        lines.append("Case #%d: %s" % (i + 1, " ".join(solvedCase)))
    return '\n'.join(lines)

def generateOutput(filename, outFile = None):
    cases = getCases(filename)
    solvedCases = [solveCase(case) for case in cases]
    output = getOutput(solvedCases)
    if outFile == None:
        outFile = filename[:-2] + "out"
    with open(outFile, "w") as h:
        h.write(output)
    
