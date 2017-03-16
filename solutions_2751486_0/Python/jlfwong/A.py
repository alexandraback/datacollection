import sys

casenum = 1
def doit(case):
    global casenum

    name, n = case.split(' ')
    n = int(n)

    consonants = 'bcdfghjklmnpqrstvwxyz'

    for consonant in consonants:
        name = name.replace(consonant, '.')

    dyn = [0] * len(name)

    for i in range(len(name) - (n-1)):
        if name[i:i+n] == '.' * n:
            dyn[i] = i + 1
        else:
            dyn[i] = dyn[i-1]

    print 'Case #%d: %d' % (casenum, sum(dyn))
    casenum += 1

raw = [x.strip() for x in sys.stdin.readlines()]
ZZZ = int(raw[0])
data = raw[1:]
for case in range(ZZZ):
    doit(data[case])
