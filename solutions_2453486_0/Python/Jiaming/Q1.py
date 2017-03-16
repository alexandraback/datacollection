def has_won(a,b,c,d):
    if a == 'T':
        a,b=b,a
    if b != a and b != 'T':
        return False
    if c != a and c != 'T':
        return False
    if d != a and d != 'T':
        return False
    if a == '.':
        return False
    return a

def is_completed(state):
    for i in state:
        for j in i:
            if j == '.':
                return False
    return True

def solve(filename):
    f = open(filename);
    out = open(filename + '.out.txt','w')
    n = int(f.readline())
    for i in xrange(n):
        state = [f.readline(),f.readline(),f.readline(),f.readline()]
        out.write("Case #" + str(i+1) + ": ")
        won = False
        for i in xrange(4):
	    if not won:
                won = has_won(state[i][0],state[i][1],state[i][2],state[i][3])
        for i in xrange(4):
	    if not won:
                won = has_won(state[0][i],state[1][i],state[2][i],state[3][i])
        if not won:
            won = has_won(state[0][0],state[1][1],state[2][2],state[3][3])
        if not won:
            won = has_won(state[0][3],state[1][2],state[2][1],state[3][0])
        if won:
            out.write(won +' won\n')
        elif is_completed(state):
            out.write('Draw\n')
        else:
            out.write('Game has not completed\n')
        f.readline()
    f.close()
    out.close()
