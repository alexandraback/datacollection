def parse():
	s = input()
	return s

def solve(s):
	k = 0
	for i in range(1, len(s)):
		if s[i-1] != s[i]: k += 1
	return k + (s[-1] == '-')

def main():
	for i in range(int(input())):
		s = parse()
		k = solve(s)
		print("Case #{}: {}".format(i+1, k))

if __name__ == "__main__": main()