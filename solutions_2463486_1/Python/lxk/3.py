import math
import itertools

def reverse_str(s):
	return s[::-1]

def reverse_num(num):
	return int(reverse_str(str(num)))

def num_len(num):
	return int(math.log10(num)) + 1

def gen_pali_from_num(num, center = None):
	l = num_len(num)
	rnum = reverse_num(num)
	if center is None:
		return num * int(math.pow(10, l)) + rnum

	return int(num * math.pow(10, l + 1)) + int(center * math.pow(10, l)) + rnum

def is_pali(num):
	s = str(num)
	return reverse_str(s) == s

def gen_all_palis(max_exp):
	palis = [[1, 2, 3]]

	for exp in range(2, max_exp + 1):
		exp_palis = None

		if exp % 2 == 0:
			factor = int(math.pow(10, exp / 2 - 1))
			exp_palis = [gen_pali_from_num(i) for i in range(factor, 3 * factor)]
		else:
			factor = int(math.pow(10, (exp - 1) / 2 - 1))

			exp_palis = []
			for center in range(0, 10):
				exp_palis.extend(gen_pali_from_num(i, center) for i in range(factor, 3 * factor))

		palis.append(exp_palis)

	return list(itertools.chain(*palis))

def gen_quad_palis(max_exp):
	palis = gen_all_palis(int(max_exp / 2))
	quad_palis = [pali * pali for pali in palis if is_pali(pali * pali)]

	quad_palis.sort()
	return quad_palis

quad_palis = gen_quad_palis(15)

fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])
for testCase in range(1, countTests + 1):
	line = lines[testCase].split()

	start = int(line[0])
	end = int(line[1])

	countQuadPalis = len([x for x in quad_palis if x >= start and x <= end])
	print "Case #" + str(testCase) + ": " + str(countQuadPalis)