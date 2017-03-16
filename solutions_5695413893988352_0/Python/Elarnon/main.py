from pulp import *

left = '1x'
right = '2y'

def main(left, right):
    assert(len(left) == len(right))
    digits = LpVariable.dicts("holes", ([0,1], range(len(right))), 0, 9, LpInteger)
    obj = LpVariable('obj', cat=LpInteger)
    prob = LpProblem("objective", LpMinimize)

    prob += obj, ''

    for i, v in enumerate(left):
        if v == '?':
            continue
        prob += digits[0][i] == int(v), ""

    for i, v in enumerate(right):
        if v == '?':
            continue
        prob += digits[1][i] == int(v), ""

    factor = 10 ** (len(left) - 1)
    lterm = 0
    rterm = 0
    for l, r in zip(digits[0].values(), digits[1].values()):
        lterm = 10 * lterm + l
        rterm = 10 * rterm + r
    prob += obj >= lterm - rterm, ''
    prob += obj >= rterm - lterm, ''

    prob.solve()

    ovalue = value(obj)

    prob += -obj, ""
    prob += obj == ovalue, ""

    prob += lterm, ""

    prob.solve()
    lvalue = value(lterm)

    prob += -lterm, ""
    prob += lterm == lvalue, ""

    prob += rterm, ""

    prob.solve()

    lv = []
    rv = []
    for l, r in zip(digits[0].values(), digits[1].values()):
        lv.append(str(int(value(l))))
        rv.append(str(int(value(r))))
    return '{} {}'.format(''.join(lv), ''.join(rv))

if __name__ == '__main__':
    import sys
    nb = int(sys.stdin.readline())
    for i in range(nb):
        print('Case #{}: {}'.format(i+1, main(*sys.stdin.readline().strip().split())))
