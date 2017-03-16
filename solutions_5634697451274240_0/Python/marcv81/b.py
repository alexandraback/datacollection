def flip(stack, count):
	new_stack = []
	for i in xrange(count-1, -1, -1):
		if stack[i] == '+':
			new_stack.append('-')
		else:
			new_stack.append('+')
	new_stack.append(stack[count:])
	return str().join(new_stack)

def count_top_smiles(stack):
	i = 0
	while (i < len(stack)) and (stack[i] == '+'):
		i += 1
	return i

def count_bottom_smiles(stack):
	i = len(stack)-1
	while (i >= 0) and (stack[i] == '+'):
		i -= 1
	return len(stack)-1 - i

def fix_stack(stack):
	count = 0
	while True:
		top_smiles = count_top_smiles(stack)
		if top_smiles == len(stack):
			return count
		if top_smiles == 0:
			bottom_smiles = count_bottom_smiles(stack)
			stack = flip(stack, len(stack) - bottom_smiles)
			count += 1
			continue
		else:
			stack = flip(stack, top_smiles)
			count += 1
			continue

with open('B-small-attempt0.in', 'r') as f:
	test_cases = int(f.readline())
	for test_case in xrange(1, test_cases + 1):
		stack = f.readline().rstrip()
		print 'Case #' + str(test_case) + ': ' + str(fix_stack(stack))
