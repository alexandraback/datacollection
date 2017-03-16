import sys

T = int(sys.stdin.readline().strip())

def flip(stack):
	current = ['+','-']
	c = 0
	count = 0
	for j in range(len(stack)-1, -1, -1):
		if stack[j] != current[c]:
			count += 1
			c = (c+1) % 2
	return count

for t in range(T):
	stack = sys.stdin.readline().strip()
	print "Case #%d: %d"%(t+1, flip(stack))



