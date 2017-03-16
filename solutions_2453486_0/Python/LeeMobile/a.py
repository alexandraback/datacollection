import sys


def check4(squares):
    '''
    Checks the 4 squares to find a winner.
    '''
    unique = set(squares)
    if len(unique) == 1:
        if "." not in unique:
            return unique.pop()
    elif len(unique) == 2:
        if "T" in unique and "." not in unique:
            unique.remove("T")
            return unique.pop()
    if "." in unique:
        return "."
    return None


f = open(sys.argv[1], 'r')
T = int(f.readline())
for i in range(T):
    case = int(i) + 1
    result = []
    rows = []
    rows.append(f.readline().strip())
    rows.append(f.readline().strip())
    rows.append(f.readline().strip())
    rows.append(f.readline().strip())

    for row in rows:
        result.append(check4(row))

    for c in range(4):
        column = (rows[0][c], rows[1][c], rows[2][c], rows[3][c])
        result.append(check4(column))
    
    slash1 = (rows[0][0], rows[1][1], rows[2][2], rows[3][3])
    slash2 = (rows[0][3], rows[1][2], rows[2][1], rows[3][0])
    result.append(check4(slash1))
    result.append(check4(slash2))

    if "X" in result:
        print "Case #%s: X won" % case
    elif "O" in result:
        print "Case #%s: O won" % case
    elif "." in result:
        print "Case #%s: Game has not completed" % case
    else:
        print "Case #%s: Draw" % case
    f.readline()
