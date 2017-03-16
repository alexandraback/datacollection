from sys import *
from fractions import gcd
f_i = open(argv[1])
f_o = open(argv[2], 'w')
cases = int(f_i.readline() [:-1])
for w in range(1, cases + 1):
    header = 'Case #' + str(w) + ': '
    string = f_i.readline() [:-1]
    quants = [int(n) for n in string.split(' ')]
    amounts = quants[:3]
    two_restr = quants[-1]
    outfits = quants[0] * quants[1] * quants[2]
    two_poss = quants[0] * quants[1] * two_restr
    plan = []
    if outfits > two_poss:
        limit = two_poss
        plan = [[j,p] for p in range(1, quants[1] + 1) for j in range(1, quants[0] + 1)]*two_restr
        if gcd(quants[0], quants[2]) == 1:
            if gcd(quants[1], quants[2]) == 1:
                plan = [a + [i % quants[2] + 1] for i,a in enumerate(plan)]
            else:
                plan = [a + [(i + i // (quants[0] * quants[1])) % quants[2] + 1 ] for i,a in enumerate(plan)]
        else:
            if gcd(quants[1], quants[2]) == 1:
                plan = [a + [(i + i // quants[0]) % quants[2] + 1] for i,a in enumerate(plan)]
            else:
                plan = [a + [(i + i // quants[0] + i // (quants[0] * quants[1])) % quants[2] + 1 ] for i,a in enumerate(plan)]
    else:
        limit = outfits
        plan = [[j,p,s] for j in range(1, quants[0] + 1) for p in range(1, quants[1] + 1) for s in range(1, quants[2] + 1)]
    f_o.write(header + str(limit) + '\n')
    for o in plan:
        f_o.write(' '.join([str(k) for k in o]) + '\n')
f_o.close()
