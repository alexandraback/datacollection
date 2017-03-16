from sys import stdin
from itertools import product

T = int(stdin.readline())

def find(lst, a):
    return [i for i, x in enumerate(lst) if x==a]

def num(x, x_unks):
    if len(x_unks) == 0:
        yield int(''.join(x))
        return
    for i in xrange(10):
        x[x_unks[0]] = chr(48 + i)
        for _num in num(x, x_unks[1:]):
            yield _num

for case in xrange(1,T+1):
    c,j = stdin.readline().strip().lower().split(' ')
    c = list(c)
    j = list(j)
    c_unks = list((find(c, '?')))
    j_unks = list((find(j,'?')))
    dif = 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
    for c_, j_ in product(num(c, c_unks), num(j, j_unks)):
        if abs(c_ - j_) < dif:
            result = c_, j_
            dif = abs(c_ - j_)
        if dif == 0:
            break
    # for c_, j_ in product(num(c, c_unks), num(j, j_unks)):
        # if abs(c_ - j_) == dif:
            # print c_, j_
        # if dif == 0:
            # break


    result = map(str, list(result))

    print 'Case #{0}: {1} {2}'.format(case, result[0].zfill(len(c)), result[1].zfill(len(j)))

