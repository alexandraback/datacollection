def find_longest_inverse(el, inverse_bffs, not_in):
	if el not in inverse_bffs:
		return [el]
	lovers = inverse_bffs[el]
	if len(lovers) == 1 and lovers[0] == not_in:
		return [el]
	return [el] + max((find_longest_inverse(x, inverse_bffs, []) for x in lovers if x != not_in), key=len)

def great_solution(bffs):
	like_each_other = set()
	inverse_bffs = {}
	ending = set()
	number_of_kids = len(bffs)
	great_ones = []
	no_bffed_kids = set(range(1, number_of_kids + 1)) - set(bffs)
	for n, el in enumerate(bffs):
		if bffs[el] == n:
			ending.add(n)
			like_each_other.add(tuple(sorted((n, el))))
		if el not in inverse_bffs:
			inverse_bffs[el] = []
		inverse_bffs[el].append(n)
	for l1, l2 in like_each_other:
		lovers_1 = find_longest_inverse(l1, inverse_bffs, l2)
		lovers_2 = find_longest_inverse(l2, inverse_bffs, l1)
		great_ones.append(list(reversed(lovers_2)) + lovers_1)
	one_solution = sum(len(x) for x in great_ones)
	return one_solution

def simple_solution(bffs):
	liked = set(bffs)
	already_visited = set()
	max_cycle = 0
	for el in liked:
		if el not in already_visited:
			visited_now = []
			initial = el
			pointer = el
			while pointer not in visited_now:
				already_visited.add(pointer)
				visited_now.append(pointer)
				pointer = bffs[pointer]
			where = find(pointer, visited_now)
			max_cycle = max([len(visited_now[where:]), max_cycle])
	return max_cycle

def find(pointer, visited):
	for ind, n in enumerate(visited):
		if n == pointer:
			return ind

def solve(bffs):
	return max([great_solution(bffs), simple_solution(bffs)])

if __name__ == "__main__":
	number_of_cases = int(raw_input())
	for i in range(number_of_cases):
		number_of_kids = int(raw_input())
		bffs = [int(x) - 1 for x in raw_input().split()]
		solution = solve(bffs)
		print "Case #{}: {}".format(i + 1, solution)