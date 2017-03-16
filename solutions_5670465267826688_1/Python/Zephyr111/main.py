import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            tmp = [(map(int, f.readline().split()), f.readline()[:-1]) for i in range(lineCount)]
            return [(s[0][1], s[1]) for s in tmp] # Assume len(s[1]) == s[0][0]

# return (Atom(a1*a2), isPositive(a1*a2))
def mulAtom(a1, a2):
    m = {
        '1': {
            '1': ('1', True),
            'i': ('i', True), 
            'j': ('j', True), 
            'k': ('k', True)
        }, 
        'i': {
            '1': ('i', True),
            'i': ('1', False), 
            'j': ('k', True), 
            'k': ('j', False)
        }, 
        'j': {
            '1': ('j', True),
            'i': ('k', False), 
            'j': ('1', False), 
            'k': ('i', True)
        }, 
        'k': {
            '1': ('k', True),
            'i': ('j', True), 
            'j': ('i', False), 
            'k': ('1', False)
        }
    }
    return m[a1][a2]

# With e = (atomString, positiveBoolean)
# return (evaluation(e), isPositive(e))
def evalExpr(e):
    (s, positive) = e
    if len(s) == 0:
        return ('1', True)
    def reduceOp(acc, n2):
        (nr, posr) = mulAtom(acc[0], n2)
        return (nr, not (acc[1] ^ posr))
    return reduce(reduceOp, s[1:], (s[0], positive))

def evalPowedExpr(e, exponent):
    state = evalExpr(e)
    p = exponent
    rem = []
    while p > 1:
        if p % 2 == 0:
            state = evalExpr(mulExpr(state, state))
        else:
            rem.append(state)
            state = evalExpr(mulExpr(state, state))
        p = p // 2
    for remState in rem[::-1]:
        state = evalExpr(mulExpr(state, remState))
    return state

# With exp_i = (atomString, positiveBoolean)
def mulExpr(exp1, exp2):
    return (exp1[0] + exp2[0], not (exp1[1] ^ exp2[1]))

# return min(i) such that evalExpr(s[:i]) == c
def evalAndLookFor(atoms, atomToLookFor):
    acc = '1'
    for i,atom in enumerate(atoms):
        acc = mulAtom(acc, atom)[0]
        if acc == atomToLookFor:
            return i+1
    if i == len(atoms):
        return -1

# return min(i) such that evalExpr(s[len(s)-i:]) == c
def evalAndLookForReversed(atoms, atomToLookFor):
    acc = '1'
    for i,atom in enumerate(atoms[::-1]):
        acc = mulAtom(atom, acc)[0]
        if acc == atomToLookFor:
            return i+1
    if i == len(atoms):
        return -1

# lemme 1: |q**2| == 1 
# so if q=reduction(s) then |reduction(s*2)|=|reduction(s)**2|=1
def solve(caseVal):
    (x, s) = caseVal
    if x <= 0:
        return False
    elif x <= 3:
        # Not optimized case
        atoms = s*x
        ipos = evalAndLookFor(atoms, 'i')
        if ipos < 0:
            return False
        tmp = evalAndLookFor(atoms[ipos:], 'j')
        if tmp < 0:
            return False
        jpos = ipos + tmp
        (_, sign) = evalExpr((atoms[:ipos], True))
        (_, sign) = evalExpr((atoms[ipos:jpos], sign))
        (elem, sign) = evalExpr((atoms[jpos:], sign))
        if elem != 'k' or sign == False:
            return False
    else:
        twoAtoms = s*2
        ilen = evalAndLookFor(twoAtoms, 'i')
        if ilen < 0: # i not found
            return False
        klen = evalAndLookForReversed(twoAtoms, 'k')
        if klen < 0: # k not found
            return False
        jpos = x*len(s)-klen
        if ilen+klen > x*len(s): # overlapping
            return False
        iexpr = evalExpr((twoAtoms[:ilen], True))
        kexpr = evalExpr((twoAtoms[-klen:], True))
        assert iexpr[0] == 'i'
        assert kexpr[0] == 'k'
        if x > 4:
            tmpExpr = evalPowedExpr((s, True), x-4)
        else:
            tmpExpr = ('1', True)
        jexprBegin = evalExpr((twoAtoms[ilen:], True))
        jexprEnd = evalExpr((twoAtoms[:-klen], True))
        jexpr = evalExpr(mulExpr(mulExpr(jexprBegin, tmpExpr), jexprEnd))
        if jexpr[0] != 'j': # remaining not equal to j (j not found)
            return False
        expr = mulExpr(mulExpr(iexpr, jexpr), kexpr)
        if expr[1] == False: # negative result
            return False
        assert expr[0] == 'ijk'
    return True

# WARNING: doesn't solve exactly the problem but a simpler case: reduce(s*x) == reduce('ijk')
def solveNaive(caseVal):
    return evalPowedExpr((s, True), x) == ('1', False)

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %s' % (caseId+1, 'YES' if result else 'NO')


if __name__ == '__main__':
    for caseId, caseVal in enumerate(getInputs()):
        writeOutput(caseId, solve(caseVal))

