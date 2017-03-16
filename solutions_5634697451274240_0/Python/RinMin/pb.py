from sys import *

def all_flipped(stack):
	for p in stack:
		if p == '-':
			return False
	return True

def flip(stack, n):
	new_stack = list(stack)
	for i in range(0, n):
		if stack[i] == '-':
			new_stack[n-i-1] = '+'
		else:
			new_stack[n-i-1] = '-'
	return new_stack

def num_same(stack, face, forward):
	count = 0
	if not forward:
		stack = reversed(stack)
	for p in stack:
		if p == face:
			count = count + 1
		else:
			return count
	return len(stack)

def num_flips(stack):
	i = 0
	while not all_flipped(stack):
		if stack[0] == '-':
			count = num_same(stack, '+', False)
			stack = flip(stack, len(stack) - count)
		else:
			count = num_same(stack, '+', True)
			stack = flip(stack, count)
		i = i + 1

	return i


fin = open(argv[1] + ".in", 'r') 
fout = open(argv[1] + ".out", 'w')

ncases = int(fin.readline())
for c in range(ncases):
	stack = fin.readline()
	fout.write("Case #" + str(c+1) + ": " + str(num_flips(list(stack)[0:-1])) + "\n")

fin.close()
fout.close()


	
