
def win(player, lines):
    for r in range(4):
        if all( char in (player, 'T') for char in lines[r] ):
            return True
    for c in range(4):
        if all( char in (player, 'T') for char in ( lines[r][c] for r in range(4) ) ):
            return True
    if all( char in (player, 'T') for char in ( lines[i][i] for i in range(4) ) ):
        return True
    if all( char in (player, 'T') for char in ( lines[i][4-i-1] for i in range(4) ) ):
        return True
    return False

def work(case_num):
    lines = [ raw_input() for i in range(4) ]
    raw_input()
    if win('X', lines):
        result = "X won"
    elif win('O', lines):
        result = "O won"
    elif any( '.' in line for line in lines ):
        result = "Game has not completed"
    else:
        result = "Draw"
    print "Case #%d: %s" % (case_num+1, result)

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        work(t)