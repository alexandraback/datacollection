from solver import solver

def possibles(c):
    n = int(c)
    if n == 0:
        return '0', '1'
    if n == 9:
        return '8', '9'
    return str(n-1), str(n), str(n+1)

def solve(c, j, pc='', pj=''):
    # Stop condition
    if not c or not j:
        yield (pc, pj)
        return
    # Pop characters
    cc, cj = c[0], j[0]
    c, j = c[1:], j[1:]
    # Complex cases
    if cc == '?' and cj != '?' and pc == pj:
        for cc in possibles(cj):
            yield from solve(c, j, pc+cc, pj+cj)
        return
    if cc != '?' and cj == '?' and pc == pj:
        for cj in possibles(cc):
            yield from solve(c, j, pc+cc, pj+cj)
        return
    if cc == '?' and cj == '?' and pc == pj:
        for cc, cj in [('0', '0'), ('0', '1'), ('1', '0')]:
            yield from solve(c, j, pc+cc, pj+cj)
        return
    # Simple cases
    if pc > pj:
        if cc == '?': cc = '0' 
        if cj == '?': cj = '9'
    elif pc < pj:
        if cc == '?': cc = '9' 
        if cj == '?': cj = '0'
    yield from solve(c, j, pc+cc, pj+cj)

def compare(arg):
    x, y = map(int, arg)
    return abs(x-y), x, y

@solver
def match(lines):
    c, j = lines[0].split()
    res = min(solve(c, j), key=compare)
    return ' '.join(res)

if __name__ == '__main__':
    match.from_cli()
