import sys

def main():
	num_test_cases = int(sys.stdin.readline())
	# print(num_test_cases)
	for i in range(num_test_cases):
		test = map(int, str(sys.stdin.readline().strip()).split(' '))
		outfits = function(*test)
		outfits_string = "\n".join([" ".join(outfit) for outfit in outfits])
		print("Case #{}: {}\n{}".format(i + 1, len(outfits), outfits_string))

def function(j, p, s, k):
	jp_combo = {}
	ps_combo = {}
	js_combo = {}

	outfits = []

	def combo_ok(combo, table):
		if combo in table:
			if table[combo] >= k:
				return False
		return True

	def add_to_table(combo, table):
		if combo in table:
			table[combo] += 1
		else:
			table[combo] = 1

	for jacket in range(1, j+1):
		for pant in range(1, p+1):
			for shirt in range(1, s+1):
				if (combo_ok((jacket, pant), jp_combo) and
					combo_ok((pant, shirt), ps_combo) and
					combo_ok((jacket, shirt), js_combo)):
					outfits.append(map(str, (jacket, pant, shirt)))
					add_to_table((jacket, pant), jp_combo)
					add_to_table((pant, shirt), ps_combo)
					add_to_table((jacket, shirt), js_combo)

	return outfits

if __name__ == '__main__':
	main()