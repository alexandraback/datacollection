def to_number(lst):
	return int(''.join(lst))

def difference_for_lists(c, j):
	return abs(int(''.join(c)) - int(''.join(j)))

def make_smallest_same(c, j):
	for i in range(len(c)):
		if c[i] == '?':
			c[i] = j[i] if j[i] != '?' else '0'
		if j[i] == '?':
			j[i] = c[i]

def fill_the_rest(c, j):
	c_is_bigger = False
	j_is_bigger = False
	for i in range(len(c)):
		if not c_is_bigger and not j_is_bigger:
			if c[i] == j[i]:
				continue
			elif c[i] > j[i]:
				c_is_bigger = True
			else:
				j_is_bigger = True
		else:
			if c[i] == '?':
				c[i] = '0' if c_is_bigger else '9'
			if j[i] == '?':
				j[i] = '0' if j_is_bigger else '9'

def check_all_possibilities(c, j, first_difference):
	i = first_difference - 1
	possible_results = []
	if c[i] == '?' and j[i] == '?':
		c[i] = j[i] = '0'
		possible_results.append(solve_for_list(c, j, i))
		c[i] = '0'
		j[i] = '1'
		possible_results.append(solve_for_list(c, j, i))
		c[i] = '1'
		j[i] = '0'
		possible_results.append(solve_for_list(c, j, i))
		c[i] = '9'
		j[i] = '0'
		possible_results.append(solve_for_list(c, j, i))
		c[i] = '0'
		j[i] = '9'
		possible_results.append(solve_for_list(c, j, i))
	elif c[i] != '?' and j[i] == '?':
		j[i] = c[i]
		possible_results.append(solve_for_list(c, j, i))
		j[i] = str((int(c[i]) + 1) % 10)
		possible_results.append(solve_for_list(c, j, i))
		j[i] = str((int(c[i]) - 1) % 10)
		possible_results.append(solve_for_list(c, j, i))
	elif j[i] != '?' and c[i] == '?':
		c[i] = j[i]
		possible_results.append(solve_for_list(c, j, i))
		c[i] = str((int(j[i]) + 1) % 10)
		possible_results.append(solve_for_list(c, j, i))
		c[i] = str((int(j[i]) - 1) % 10)
		possible_results.append(solve_for_list(c, j, i))
	else:
		return solve_for_list(c, j, i)

	smallest = possible_results[0]
	for possible_result in possible_results:
		smallest = get_better_result(smallest, possible_result)
	
	return smallest

def get_better_result(first, second):
	if first[2] < second[2] or (first[2] == second[2] and to_number(first[0]) < to_number(second[0])) or (first[2] == second[2] and to_number(first[0]) == to_number(second[0]) and to_number(first[1]) < to_number(second[1])):
		return first
	return second

def find_first_difference(c, j):
	for i in range(len(c)):
		if c[i] != '?' and j[i] != '?' and c[i] != j[i]:
			return i
	return -1

def solve_for_list(c, j, first_difference):
	c = list(c)
	j = list(j)
	if first_difference == -1:
		make_smallest_same(c, j)
	elif first_difference == 0:
		fill_the_rest(c, j)
	else:
		c, j, diff = check_all_possibilities(c, j, first_difference)
	return c, j, difference_for_lists(c, j)

def operation(inp):
	c, j = inp.split()
	c = list(c)
	j = list(j)
	first_difference = find_first_difference(c, j)
	c1, j1, diff = solve_for_list(c, j, first_difference)
	return ''.join(c1), ''.join(j1)

amount_of_inputs = input()
for index in range(amount_of_inputs):
	current_input = raw_input()
	case_result1, case_result2 = operation(current_input)
	print("Case #%s: %s %s" % (index + 1, case_result1, case_result2))
