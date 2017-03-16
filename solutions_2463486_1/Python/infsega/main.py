def get_palindromes(v):
	rv = palindromes(v)
	if len(v) < 4:
		rv += get_palindromes('0' + v)
	return rv

def palindromes(v):
	rv = list()
	rv.append(v + v[::-1])
	rv.append(v + v[-2::-1])
	return rv

def is_palindrome(v):
	for i in range(len(v)):
		if v[i] != v[len(v) - i - 1]:
			return False
	return True

p = set()
for i in range(10000):
	for v in get_palindromes(str(i)):
		isquare = int(v) ** 2
		if is_palindrome(str(isquare)):
			p.add(isquare)

def count_values(inp):
	a,b = [int(i) for i in inp.readline().split(' ')]
	counter = 0
	for v in p:
		if (a <= v) and (v <= b):
			counter += 1
	return counter

def solve(inp, out):
	n = int(inp.readline())
	for i in xrange(1,n+1):
		res = count_values(inp)
		out.write("Case #%d: %s\n" % (i, res))

def main():
	with open("C-large-1.in", "rt") as inp:
		with open("C-large-1.out", "wt") as out:
			solve(inp, out)

if __name__ == '__main__':
	main()
