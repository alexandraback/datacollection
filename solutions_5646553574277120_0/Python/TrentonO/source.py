# C Small
from itertools import combinations

def possible_transactions(denom, max_transaction):
	pos = set([0])
	for coin in denom:
		new_pos = set()
		for trans in pos:
			if trans + coin <= max_transaction:
				new_pos.add(trans + coin)
		pos.update(new_pos)
	return pos

def solve(max_coins, max_transaction, denominations):
	num_denominations = len(denominations)
	denom = set(denominations)
	for length in xrange(num_denominations, max_transaction+1):
		for denom_list in combinations(range(1, max_transaction + 1), length):
			denom_set = set(denom_list)
			if denom.issubset(denom_set) and len(possible_transactions(denom_set, max_transaction)) == max_transaction + 1:
				return len(denom_list) - num_denominations







#############################################################

inF = open('test.in')
case_sols = []
for case in xrange(int(inF.readline())):
	max_coins, num_denominations, max_transaction = map(int, inF.readline().split())
	denominations = map(int, inF.readline().split())
	case_sols.append(solve(max_coins, max_transaction, denominations))

inF.close()

B_sol = open('solution.txt', 'w')
for i, sol in enumerate(case_sols, start=1):
	B_sol.write('Case #{0}: '.format(i) + str(sol) + '\n')

B_sol.close()