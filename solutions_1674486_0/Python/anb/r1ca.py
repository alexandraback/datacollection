from sys import stdin

def is_diamond(classes, N):
	for c in classes:
		if len(c) == 0:
			continue
		counts = [ 0 ] * N
		stack = []
		for a in c:
			stack.append(a)
		while len(stack) > 0:
			cl = stack.pop()
			if counts[cl] == 1:
				return True
			counts[cl] += 1
			for a in classes[cl]:
				stack.append(a)
			
	return False
			

def main():
	T = int(stdin.readline())
	for Ti in xrange(T):
		N = int(stdin.readline())
		classes = [ [] for i in xrange(N) ]
		for Ni in xrange(N):
			line = map(int, stdin.readline().rstrip().split(' '))
			classes[Ni] = line[1:]
			classes[Ni] = map(lambda x: x - 1, classes[Ni])
		
		if is_diamond(classes, N):
			print 'Case #%d: Yes' % (Ti + 1)
		else:
			print 'Case #%d: No' % (Ti + 1)

if __name__ == '__main__':
	main()