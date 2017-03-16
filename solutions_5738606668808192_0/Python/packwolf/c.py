from sympy import primefactors
from itertools import product
with open('c.in') as f:
    with open('c.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            n, j = map(int, f.readline().split())
            res = []
            core = product('01', repeat=n-2)
            for num in core:
                number = '1' + ''.join(num) + '1'
                ints = [int(number, k) for k in range(2, 11)]
                good = True
                pfs = []
                for it in ints:
                    pf = primefactors(it)[0]
                    if pf == it:
                        good = False
                        break
                    else:
                        pfs.append(pf)
                if good:
                    res.append([number]+map(str, pfs))
                    j -= 1
                    print j
                if not j:
                    break
            out.write('Case #1:\n')
            print 'Case #1:'
            for r in res:
                print ' '.join(r)
                out.write(' '.join(r) + '\n')