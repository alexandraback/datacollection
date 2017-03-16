from itertools import product
from collections import Counter

INPUT_FILE = "C-small-attempt0.in"


def solve_case(case):
    J, P, S, K = [int(x) for x in case.split(' ')]
    Js = ['J{}'.format(i) for i in range(1, J+1)]
    Ps = ['P{}'.format(i) for i in range(1, P+1)]
    Ss = ['S{}'.format(i) for i in range(1, S+1)]

    c = Counter()
    outfits = []
    for j, p, s in product(Js, Ps, Ss):
        if c[(j, p)] < K and c[(j, s)] < K and c[(p, s)] < K:
            c[(j, p)] += 1
            c[(j, s)] += 1
            c[(p, s)] += 1
            outfits.append((j[1], p[1], s[1]))

    return str(len(outfits)) + '\n' + '\n'.join([' '.join(o) for o in outfits])

def main():
    with open(INPUT_FILE) as fh:
        cases = [l.rstrip() for l in fh.readlines()[1:]]

    sol = ''
    for i in range(len(cases)):
        sol += "Case #{}: {}\n".format(i+1, solve_case(cases[i]))

    with open(INPUT_FILE.replace('.in', '.out'), 'w') as fh:
        fh.write(sol)

if __name__ == '__main__':
    main()
