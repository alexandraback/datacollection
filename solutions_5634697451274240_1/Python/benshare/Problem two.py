def isDone(stack):
	return '-' not in stack

def getFirstMatching(stack):
	char = stack[0]
	num = 0
	while num < len(stack) and stack[num] == char:
		num += 1
	return num

f = open('B-large.in')
curr_line = f.readline()
numCases = int(curr_line)
for i in range(0,numCases):
	curr_line = f.readline()
	if (curr_line == ""):
		print "Case #%d: 0" %(i+1)
	flips = 0
	stack = curr_line
	while not isDone(stack):
		numToFlip = getFirstMatching(stack)
		char = '+'
		if (stack[0] == '+'):
			char = '-'
		newStack = ""
		for n in range(0,numToFlip):
			newStack += char
		newStack += stack[numToFlip:]
		stack = newStack
		flips += 1
	print "Case #%d: %d" %(i+1,flips)