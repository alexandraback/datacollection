import itertools

def any_value_payable_with_denominations(max_value, denominations):
	payables = [False] * (max_value + 1)
	payables[0] = True
	for include in itertools.product((True, False), repeat = len(denominations)):
		sum = 0
		for index in range(len(denominations)):
			if include[index]:
				sum += denominations[index]
				if (sum > max_value):
					break
				payables[sum] = True
		if False not in payables:
			return True
	return False

def solve(max_same_coins, denomination_count, max_value, denominations):
	missing_denominations = list(set(range(1, max_value + 1)) - set(denominations))
	for denominations_to_add_count in range(len(missing_denominations) + 1):
		denomination_combination = itertools.combinations(missing_denominations, denominations_to_add_count)
		for denominations_to_add in denomination_combination:
			if any_value_payable_with_denominations(max_value, list(set(denominations) | set(list(denominations_to_add)))):
				return denominations_to_add_count

testcase_count = int(input())
for testcase_index in range(1, testcase_count + 1):
	C, D, V = [int(x) for x in input().split()]
	d = [int(x) for x in input().split()]
	result = solve(C, D, V, d)
	print("Case #%d: %d" % (testcase_index, result))