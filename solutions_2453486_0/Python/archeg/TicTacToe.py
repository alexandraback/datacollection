__author__ = 'archeg'

def analyzeTicTacToe(field):
    toCheck = []
    mainDiagonal = []
    subDiagonal = []
    for i in range(4):
        toCheck.append(field[i])
        toCheck.append([f[i] for f in field])
        mainDiagonal.append(field[i][i])
        subDiagonal.append(field[3-i][i])
    toCheck.append(mainDiagonal)
    toCheck.append(subDiagonal)

    anyMoveAvailable = False
    for c in toCheck:
        print c
        if all(e == 'X' or e == 'T' for e in c):
            return "X won"
        if all(e == 'O' or e == 'T' for e in c):
            return 'O won'
        if any(e == '.' for e in c):
            anyMoveAvailable = True
    if anyMoveAvailable:
        return "Game has not completed"
    else:
        return "Draw"

def run():
    fi = open('input.in', 'r')
    strings = fi.readlines()
    n = int(strings[0])
    fields = []
    strings = [s.strip() for s in strings]
    for i in range(1, 5*n+1, 5):
        fields.append(strings[i:i+4])

    output = []
    i = 1
    for f in fields:
        output.append("Case #%i: %s\n" % (i, analyzeTicTacToe(f)))
        i+=1

    with open('output.out', 'w') as fo:
        fo.writelines(output)
    fo.close()

run()