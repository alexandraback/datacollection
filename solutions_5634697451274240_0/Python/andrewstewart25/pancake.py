import string,sys
table = string.maketrans('+-','-+')

def flip(stack, pos):
	return stack[:pos].translate(table) + stack[pos:]
	
def f(stack):
	count = 0
	while True:
		index = stack.rfind('-');
		if index == -1:break
		count +=1
		stack = flip(stack, index+1)
	return count

total = None
count = 0
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	count += 1
	print "Case #%s: %s"%(count,f(line))
	if count == total:
		break