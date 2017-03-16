def get_correspondent(K, C, position):
	res = 0
	for el in range(C):
		res += position * K**el
	return res + 1

def next_need_to_know(need_to_know, K):
	pairs = [tuple(need_to_know[i:i+2]) for i in range(0, len(need_to_know), 2)]
	for pair in pairs:
		if len(pair) == 2:
			a, b = pair
			yield a * K + b
		else:
			a = pair[0]
			yield a * K + a

def solve(K, C, S):
	if S * 2 ** (C - 1) < K:
		return None
	need_to_know = list(range(K))
	for i in range(1, C):
		need_to_know = list(next_need_to_know(need_to_know, K))
	assert len(need_to_know) <= S
	return need_to_know

if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		K, C, S = [int(x) for x in raw_input().split(" ")]
		solution = solve(K, C, S)
		if solution is None:
			print "Case #{}: {}".format(i + 1, "IMPOSSIBLE")
		else:
			print "Case #{}: {}".format(i + 1, " ".join(str(x + 1) for x in solution))