def flip(c):
	return {"+":"-", "-":"+"}[c]

def flipped(x,n):
	return "".join(reversed(map(flip, x[:n+1]))) + x[n+1:]

def greedy(x):
	j = len(x)-1
	ret = 0
	while True:
		while j >= 0 and x[j] == "+":
			j -= 1
		
		if j < 0:
			break

		i = 0
		while x[i] == "+":
			i += 1

		if i > 0:
			x = flipped(x, i-1)
			ret += 1

		x = flipped(x,j)
		ret += 1
		assert x[j] == "+"

	return ret

if __name__ == '__main__':
	T = int(raw_input())
	for t in range(T):
		x = raw_input().strip()
		print "case #%d: %s" % (t+1,greedy(x))
