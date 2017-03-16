import sys
from itertools import chain, combinations
from utils import stripped_lines, ints

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))



def solve_next_case(lines):
    case = lines.next()
    numbers = ints(case)[1:]
    candidates = ((sum(subset), subset) for subset in powerset(numbers))
    total_to_subset = {}
    for candidate in candidates:
        total, subset = candidate
        try:
            return '\n'+'\n'.join(' '.join(str(i) for i in subset) for subset in [total_to_subset[total], subset])
        except KeyError:
            total_to_subset[total] = subset
    return '\nImpossible'

def main():
    fin_name = sys.argv[1]
    with open(fin_name) as fin:
        lines = stripped_lines(fin)

        numcases = int(lines.next())

        for caseno in range(1, numcases+1):
            result = solve_next_case(lines)
            
            outstr = 'Case #%d: %s' % (caseno, result)
            print outstr

if __name__ == '__main__':
    main()