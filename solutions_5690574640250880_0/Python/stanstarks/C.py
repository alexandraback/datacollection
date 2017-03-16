import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]
    
def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

################################################################################

def read_case(f):
    R, C, M= read_ints(f)
    return R, C, M

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')


################################################################################
def oob(bd, r, c):
    if r < 0 or r >= len(bd):
        return True
    if c < 0 or c >= len(bd[0]):
        return True
    return False
    
def around(bd, r, c):
    poslist = []
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i==0 and j==0: continue
            pos = [r+i, c+j]
            if oob(bd, pos[0], pos[1]): continue
            poslist.append(pos)
    return poslist

def modif(bd):
    for i in range(len(bd)):
        for j in range(len(bd[0])):
            if bd[i][j] == 'o': continue
            for ppos in around(bd, i, j):
                if bd[ppos[0]][ppos[1]] == 'o':
                    bd[i][j] = '.'
                    break
    for i in range(len(bd)):
        for j in range(len(bd[0])):
            if bd[i][j] == 'o': bd[i][j] = '.'
    return bd
    
def test(M, ne, bd, r, c):
    #print r, c
    if bd[r][c] == 'o':
        return None
    oldne = ne
    alist = around(bd, r, c)
    alist.append([r, c])
    for pos in alist:
        if bd[pos[0]][pos[1]] == 'o': continue
        mine = 1
        for ppos in around(bd, pos[0], pos[1]):
            if bd[ppos[0]][ppos[1]] == 'o':
                #print pos, 'near 0'
                mine = 0
                break
        ne = ne + mine
    #print ne
    R = len(bd)
    C = len (bd[0])
    if ne > R*C-M:
        ne = oldne
        return None
    bd[r][c] = 'o'
    if ne == R*C-M:
        return modif(bd)
    for pos in around(bd, r, c):
        res = test(M, ne, bd, pos[0], pos[1])
        if not res == None:
            return res
    bd[r][c] = '*'
    return None

def genres(res):
    resstr = ''
    for r in res:
        resstr = resstr + '\n' + ''.join(r)
    return resstr
    
def solve_small(case):
    R, C, M = case
    if M == R*C-1:
        bd = []
        for k in range(R):
            bd.append(list('*'*C))
        bd[0][0] = 'c'
        return genres(bd)
    for i in range((R+1)/2):
        for j in range((C+1)/2):
            #print 'case'
            bd = []
            for k in range(R):
                bd.append(list('*'*C))
            res = test(M, 0, bd, i, j)
            if not res == None:
                res[i][j] = 'c'
                return genres(res)
    return "\nImpossible"
    
solve_large = solve_small

solve(solve_large, 'C-small-attempt5')

