import sys

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')

vowels = {'a':1, 'e':1, 'i':1, 'o':1, 'u':0}
num = int(input_file.readline())
for i in range(num):
	input_ = input_file.readline().split()
	text = input_[0]
	L = len(text)
	n = int(input_[1])
	found_ = False
	found2_ = []
	pos = 0
	curr = 0
	consec = 0
	for t in text:
		if t not in vowels:
			consec += 1
			if consec == n:
				found_ = True
		else:
			if found_:
				found2_.append((pos, curr))
				found_ = False
			consec = 0
			pos = curr + 1
		curr += 1
	if found_:
		found2_.append((pos, L))

	print found2_
	sub_ = 0
	s = 0
	for (pos_1, pos_2) in found2_:
		while s <= pos_2 - n:
			if s <= pos_1:
				sub_ += L - (pos_1 + n) + 1
			else:
				sub_ += L - (s + n) + 1
			s += 1

	output_file.write('Case #' + str(i + 1) + ': ' + str(sub_) + '\n')

input_file.close()
output_file.close()
