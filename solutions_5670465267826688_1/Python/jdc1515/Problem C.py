with open("C-large.in") as f:
    lines = f.readlines()

outputname = 'outputClarge.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def compound(instr):
    i = 0
    neg = False

    cur = "1"

    while i < len(instr):
        if instr[i] == "-":
            neg = not neg
        elif cur == "1":
            cur = instr[i]
        elif cur == "i":
            if instr[i] == "i":
                cur = "1"
                neg = not neg
            elif instr[i] == "j":
                cur = "k"
            elif instr[i] == "k":
                cur = "j"
                neg = not neg
        elif cur == "j":
            if instr[i] == "i":
                cur = "k"
                neg = not neg
            elif instr[i] == "j":
                cur = "1"
                neg = not neg
            elif instr[i] == "k":
                cur = "i"
        elif cur == "k":
            if instr[i] == "i":
                cur = "j"
            elif instr[i] == "j":
                cur = "i"
                neg = not neg
            elif instr[i] == "k":
                cur = "1"
                neg = not neg


        #if the next char is 1, it's skipped automatically
        i += 1
    if neg:
        return "-" + cur
    return cur

def printresult(i, yesno):
    yesnostr = "NO"
    if yesno:
        yesnostr = "YES"
    f.write("Case #" + str(i+1) + ": " + yesnostr + "\n") 

for i in range(cases):
    LXstr = lines[linenum].split(" ")
    linenum += 1
    L = int(LXstr[0])
    X = int(LXstr[1])

    cur = lines[linenum].rstrip()
    linenum += 1

    #check if we get -1 first
    simplifiedX = X % 4 #any sequence repeated 4 times gives 1
    if compound(cur * simplifiedX) != "-1":
        printresult(i, False)
        continue
        

    j = 0
    curdigit = "1"
    teststr = cur
    if X >= 4:
        teststr *= 4 #repeat the string
    else:
        teststr *= X
    while j < len(teststr) and curdigit != "i":
        curdigit = compound(curdigit + teststr[j])
        j += 1
    if j == len(teststr):
        printresult(i, False)
        continue
    firsti = j

    j = len(teststr) - 1
    curdigit = "1"
    while j >= 0 and curdigit != "k":
        curdigit = compound(teststr[j] + curdigit)
        j -= 1
    if j == -1:
        printresult(i, False)
        continue
        
    firstk = len(teststr) - j - 1

    if i == 5:
        print(teststr)
        print(firstk)

    if firstk + firsti < X * L:
        printresult(i, True)
    else:
        printresult(i, False)


f.close()

with open(outputname, 'r') as f:
    print(f.read())
