def parse():
	x = int(input())
	return x

def solve(x):
	if not x: return "INSOMNIA"
	k = 0
	l = [False]*10
	while not all(l):
		k += x
		for c in str(k): l[int(c)] = True
	return k

def main():
	for i in range(int(input())):
		x = parse()
		y = solve(x)
		print("Case #{}: {}".format(i+1, y))

if __name__ == "__main__": main()