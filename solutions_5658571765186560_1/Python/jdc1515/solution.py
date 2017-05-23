with open("D-large.in") as f:
    lines = f.readlines()

outputname = 'outputDlarge.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def div_ceil(a, b):
    return -(-a // b)

def printresult(i, richardwins):
    name = "GABRIEL"
    if richardwins:
        name = "RICHARD"
    f.write("Case #" + str(i+1) + ": " + name + "\n")

for i in range(cases):
    line = lines[linenum].split(" ")
    X, R, C = [int(j) for j in line]
    R, C = max(R,C), min(R,C)
    linenum += 1

    if (R*C % X) != 0: #Every X-omino is the same # of blocks
        printresult(i, True)
        continue
    if X == 1: #Edge case; Gabriel always wins
        printresult(i, False)
        continue
    if R < X: #Richard wins with a straight line
        printresult(i, True)
        continue
    if C < div_ceil(X, 2): #Richard wins with an L-shaped block
        printresult(i, True)
        continue
    if C > div_ceil(X, 2): #Gabriel builds around Richard
        printresult(i, False)
        continue
    if X >= 7: #Richard makes a loop
        printresult(i, True)
        continue

    #This is the only interesting case; C == ceil(X/2), R >= X
    maxshift = ((X - 1) // 2) * div_ceil(X-1, 2)
    solutionfound = False
    for shift in range(maxshift + 1):
        found = False
        for n in range(R - (X // 2 + 1) + 1):
            if (n*C + shift) % X == 0:
                found = True
                break
        if not found: #Richard wins with some funky block
            printresult(i, True)
            solutionfound = True
            break
    if not solutionfound:
        printresult(i, False) #Gabriel can win in every case

f.close()

with open(outputname, 'r') as f:
    print(f.read())
