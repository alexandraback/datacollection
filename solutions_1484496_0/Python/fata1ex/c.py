from itertools import combinations
import math
from time import time


def solve(solver, fname_in, fname_out=None):
    if fname_out is None:
		fname_out = ''.join([fname_in, '.out'])
    fname_in = ''.join([fname_in, '.in'])
		
    with open(fname_in, 'r') as fin, open(fname_out, 'w') as fout:
		T = int(next(fin).strip())
		for case_n in xrange(1, T+1):
			case = read_case(fin)
			result = solver(case)
			write_case(fout, case_n, result)

def read_case(f):
    case = map(int, next(f).split())
    return case[1:]

def write_case(f, i, res):
	if not res:
		res = 'Impossible'
	else:
		res = '\n'.join([' '.join(map(str,res[0])), ' '.join(map(str,res[1]))])
	
	f.write('Case #{0}:\n{1}\n'.format(i, res))

################################################################################

def solve_small(case):
	
	selection = dict()
	for count in xrange(1, len(case)):
		selection.update({count:list(combinations(case, count))})
	
	sum_map = dict()
	for key in selection.keys():
		for collection in selection[key]:
			s = sum(collection)
			if s in sum_map:
				if collection != sum_map[s]:
					return [collection, sum_map[s]]
			else:
				sum_map.update({s:collection})
				
	return None




t = time()
solve(solve_small, 'c')

print time() - t















