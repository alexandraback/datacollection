def solve(xs):
    if (any(set(x)==set('OT') for x in xs)): return 'O won'
    if (any(set(x)==set('O') for x in xs)): return 'O won'
    if (any(set(x)==set('XT') for x in xs)): return 'X won'
    if (any(set(x)==set('X') for x in xs)): return 'X won'
    d = set((xs[0][0],xs[1][1],xs[2][2],xs[3][3]))
    if d in (set('O'),set('OT')): return 'O won'
    if d in (set('X'),set('XT')): return 'X won'
    d = set((xs[0][3],xs[1][2],xs[2][1],xs[3][0]))
    if d in (set('O'),set('OT')): return 'O won'
    if d in (set('X'),set('XT')): return 'X won'
    for j in range(4):
        c = set(xs[i][j] for i in range(4))
        if c in (set('O'),set('OT')): return 'O won'
        if c in (set('X'),set('XT')): return 'X won'
    if any('.' in x for x in xs): return 'Game has not completed'
    return 'Draw'

rd = raw_input
for tc in range(1,1+int(rd())):
    print 'Case #%d: %s' % (tc, solve([rd() for _ in range(4)]))
    rd()

