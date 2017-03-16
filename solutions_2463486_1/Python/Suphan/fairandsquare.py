import sys

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

def palindrome(n, palins):
	if n == 1:
		palins += ['0', '1', '2']
		return palins
	elif n == 2:
		palins += ['00', '11', '22']
		return palins

	pal = palindrome(n - 2, palins)
	temp = []

	for x in ['0', '1', '2']:
		for p in pal:
			num = x + p + x
			s = 0
			for p0 in num:
				s += int(p0) * int(p0)
			if s < 10:
				temp.append(num)
	palins += temp
	return temp

def get_all_palins():
	bs_palins = [3]
	palins = []
	palindrome(51, palins)
	for k in palins:
		if k[0] != '0':
			bs_palins.append(int(k))
	palins = []
	palindrome(52, palins)
	for k in palins:
		if k[0] != '0':
			bs_palins.append(int(k))
	bs_palins = sorted(bs_palins)
	return bs_palins

bs_palins = get_all_palins()
sq_palins = []
for p in bs_palins:
	sq_palins.append(p * p)
print len(bs_palins), len(sq_palins)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')
num = int(input_file.readline())
for i in range(num):
	bound = input_file.readline().strip().split()
	min_bound = int(bound[0])
	max_bound = int(bound[1])

	found = 0
	for p2 in sq_palins:
		if p2 >= min_bound and p2 <= max_bound:
			found += 1
	output_file.write('Case #' + str(i + 1) + ': ' + str(found) + '\n')

input_file.close()
output_file.close()
