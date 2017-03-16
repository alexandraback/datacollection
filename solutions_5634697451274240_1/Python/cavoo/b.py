import itertools

def readint():
	return int(input())

def num_flips(pancakes):
	groups = list(itertools.groupby(pancakes))
	n = len(groups)
	if groups[-1][0] == '+':
		n -= 1

	return n

def main():
	N = readint()

	for t in range(1, N + 1):
		pancakes = input().strip()
		print("Case #%d: %s" % (t, num_flips(pancakes)))

main()
