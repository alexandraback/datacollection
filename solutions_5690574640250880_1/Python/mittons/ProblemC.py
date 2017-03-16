
def visualizeNormalCase(R, C, safeColumns, safeRows, extraBottomRow, secondExtraBottomRow):
    visualString = ""
    for row in xrange(R):
        if row < safeRows:
            visualString += ("."*safeColumns + "*"*(C-safeColumns) + "\n")
        elif row == safeRows:
            visualString += ("."*extraBottomRow + "*"*(C-extraBottomRow) + "\n")
        elif row == (safeRows + 1):
            visualString += ("."*secondExtraBottomRow + "*"*(C-secondExtraBottomRow) + "\n")
        else:
            visualString += "*"*C + "\n"
    visualString = "c" + visualString[1:-1]
    return visualString

def solve(R, C, M):
    impossible = "Impossible"
    if M == 0:
        visualString = ("."*C + "\n")*R
        return "c" + visualString[1:-1]
    if R*C == M:
        return impossible
    if R*C == M+1:
        visualString = ("*"*C + "\n")*R
        return "c" + visualString[1:-1]
    safeSpots = R*C-M
    if R == 1 or C == 1:
        if C == 1:
            visualString = "c\n" + ((".\n")*(safeSpots - 1)) + ("*\n"*(R - safeSpots - 1)) + "*"
            return visualString
        if R == 1:
            visualString = "c" + ("."*(safeSpots - 1)) + ("*"*(C - safeSpots))
            return visualString
    if safeSpots < 4:
        return impossible
    if R == 2 and C == 2:
        return impossible
    if R == 2 or C == 2:
        if M % 2 == 0:
            if R == 2:
                return visualizeNormalCase(R, C, safeSpots/2, 2, 0, 0)
            if C == 2:
                return visualizeNormalCase(R, C, 2, safeSpots/2, 0, 0)
        else:
            return impossible
    if safeSpots == 5 or safeSpots == 7:
        return impossible

    safeColumns = 2
    safeRows = 2
    extraBottomRow = 0
    secondExtraBottomRow = 0

    if safeSpots % 2 == 1 and safeSpots <= C*2 + 1:
        safeColumns = (safeSpots - 3)/2
        extraBottomRow = 3
    elif safeSpots % 2 == 0 and safeSpots <= C*2:
        safeColumns = safeSpots/2
    else:
        safeColumns = C
        if (safeSpots - C*2) % C == 1:
            extraBottomRow = C - 1
            secondExtraBottomRow = 2
            safeRows = (safeSpots - C - 1)/C
        else:
            extraBottomRow = safeSpots % C
            safeRows = (safeSpots - extraBottomRow)/C
    return visualizeNormalCase(R, C, safeColumns, safeRows, extraBottomRow, secondExtraBottomRow)

inp = open("C-large.in", 'r')
outp = open("C-large.out", 'w')

T = int(inp.readline())

for testCase in xrange(T):
    l = map(lambda x: int(x), inp.readline()[0:-1].split(" "))
    R = l[0]
    C = l[1]
    M = l[2]
    outp.write("Case #{}:\n{}\n".format(testCase + 1, solve(R, C, M)))
outp.close()
