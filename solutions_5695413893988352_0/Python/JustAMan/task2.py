import sys

def getvars(ch):
    if ch == '?':
        return ['0', '9']
    return [str((int(ch) + diff) % 10) for diff in (-1, 0, 1)]

def gennums(v, result):
    if not v:
        return result
    nextResult = []
    for start in result:
        for dig in v[0]:
            nextResult.append(start + dig)
    return gennums(v[1:], nextResult)

def fmt(v, startlen):
    return ('0' * startlen + str(v))[-startlen:]

def solve(c, j):
    startlen = len(c)
    p1, p2 = [], []
    for d1, d2 in zip(c, j):
        '''
        if d1 == '?' and d2 == '?':
            p1.append(['0', '9'])
            p2.append(['0', '9'])
        elif d1 == '?' and d2 != '?':
            p1.append(getvars(d2))
            p2.append([d2])
        elif d1 != '?' and d2 == '?':
            p1.append([d1])
            p2.append(getvars(d1))
        else:
            p1.append([d1])
            p2.append([d2])

        '''
        if d1 == '?':
            p1.append(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])
        else:
            p1.append([d1])
        if d2 == '?':
            p2.append(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])
        else:
            p2.append([d2]) #'''

    cv = sorted([int(x) for x in gennums(p1, [''])])
    cj = sorted([int(x) for x in gennums(p2, [''])])

    '''
    lp1, lp2 = 1, 1
    for x in p1:
        lp1 *= len(x)
    for x in p2:
        lp2 *= len(x)
    #print lp1, len(cv), lp2, len(cj)
    assert lp1 == len(cv) == len(set(cv)) and lp2 == len(cj) == len(set(cj))
    '''

    diff = []
    for v1 in cv:
        mindiff = min((abs(v2 - v1) for v2 in cj))
        for v2 in cj:
            if abs(v2 - v1) == mindiff:
                diff.append((mindiff, v1, v2))
    _, v1, v2 = min(diff)

    return '%s %s' % (fmt(v1, startlen), fmt(v2, startlen))

def main(inFile):
    #print gennums([['0', '1', '2', '3', '4' , '5', '6', '7', '8', '9']] * 3, [''])
    #return
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            C, J = inp.readline().strip().split()
            out.write('Case #%d: %s\n' % (t + 1, solve(C, J)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
