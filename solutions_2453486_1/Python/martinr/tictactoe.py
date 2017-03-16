

def count_wins(B, p):
    # rows
    for r in B:
        if r.count(p) == 4 or r.count(p) >= 3 and r.count('T') == 1:
           return 1

    # cols
    for c in range(4):
        cnt = 0
        for r in range(4):
            if B[r][c] == p or B[r][c] == 'T':
                cnt += 1
        if cnt == 4: return 1

    # diagonals
    cnt = 0
    for i in range(4):
        if B[i][i] == p or B[i][i] == 'T':
            cnt += 1
    if cnt == 4: return 1

    cnt = 0
    for i in range(4):
        if B[i][3-i] == p or B[i][3-i] == 'T':
            cnt += 1
    if cnt == 4: return 1

    return 0

def exists_free_fields(B):
    return B[0].count('.') != 0 or B[1].count('.') != 0 or B[2].count('.') != 0 or B[3].count('.') != 0

def solve(B):
    X = count_wins(B, 'X')
    O = count_wins(B, 'O')

    if (X == 0) and (O == 0):
        return 'Game has not completed' if exists_free_fields(B) else 'Draw'
    elif (X != 0) and (O != 0):
        return 'Draw' # impossible!
    elif (X != 0) and (O == 0):
        return 'X won'
    else:
        return 'O won'

n = int(input())
for t in range(1, n+1):
    B = []
    for _ in range(4):
        B.append(raw_input())
    if t != n:
        raw_input()

    print "Case #%d: %s" % (t, solve(B))


