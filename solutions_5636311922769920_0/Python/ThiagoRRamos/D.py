def get_correspondent(K, C, position):
	res = 0
	for el in range(C):
		res += position * K**el
	return res + 1

def solve(K, C, S):
	if S == K:
		return [get_correspondent(K, C, i) for i in range(S)]

if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		K, C, S = [int(x) for x in raw_input().split(" ")]
		solution = solve(K, C, S)
		if solution is None:
			print "Case #{}: {}".format(i + 1, "IMPOSSIBLE")
		else:
			print "Case #{}: {}".format(i + 1, " ".join(str(x) for x in solution))