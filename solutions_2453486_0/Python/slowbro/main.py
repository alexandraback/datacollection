import sys

def check(vec):
    Oflag = True
    Xflag = True
    for v in vec:
        if v == 'O':
            Xflag = False
        elif v == 'X':
            Oflag = False
        elif v == '.':
            Xflag = False
            Oflag = False
        if not (Xflag or Oflag):
            return Oflag, Xflag
    return Oflag, Xflag

def solve(B):
    Owin = False
    Xwin = False
    hasDot = False
    for row in B:
        if '.' in row: hasDot = True
        Ocheck, Xcheck = check(row)
        if Ocheck: Owin = True
        if Xcheck: Xwin = True
        if Owin and Xwin:
            return 'Draw'

    for j in range(4):
        col = [r[j] for r in B]
        if '.' in col: hasDot = True
        Ocheck, Xcheck = check(col)
        if Ocheck: Owin = True
        if Xcheck: Xwin = True
        if Owin and Xwin:
            return 'Draw'

    diag1 = [r[i] for (i,r) in enumerate(B)]
    if '.' in diag1: hasDot = True
    Ocheck, Xcheck = check(diag1)
    if Ocheck: Owin = True
    if Xcheck: Xwin = True
    if Owin and Xwin:
        return 'Draw'
    diag2 = [r[i] for (i,r) in zip([3,2,1,0], B)]
    if '.' in diag2: hasDot = True
    Ocheck, Xcheck = check(diag2)
    if Ocheck: Owin = True
    if Xcheck: Xwin = True

    if Owin and Xwin:
        return 'Draw'
    elif Owin: return 'O won'
    elif Xwin: return 'X won'
    elif hasDot: return 'Game has not completed'
    else: return 'Draw'


if __name__ == '__main__':
    fh = open(sys.argv[1], 'rb')
    T = int(fh.readline().strip())
    for i in range(1, T+1):
        B = []
        for j in range(4):
            B.append(fh.readline().strip())
        output = solve(B)
        fh.readline()
        print "Case #{}: {}".format(i, output)


