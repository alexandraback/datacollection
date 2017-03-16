n = int(raw_input())

def get_phone_number(s):
	counts = [0] * 10
	# print s

	# Fist patch : 0,2,4,6,8
	# Get zero
	counts[0] = s.count("Z")
	for i in xrange(counts[0]):
		for c in ["Z","E","R","O"]:
			s.remove(c)

	# Get two
	counts[2] = s.count("W")
	for i in xrange(counts[2]):
		for c in ["T","W","O"]:
			s.remove(c)

	# Get four
	counts[4] = s.count("U")
	for i in xrange(counts[4]):
		for c in ["F","O","U","R"]:
			s.remove(c)

	# Get six
	counts[6] = s.count("X")
	for i in xrange(counts[6]):
		for c in ["S","I","X"]:
			s.remove(c)

	# Get eight
	counts[8] = s.count("G")
	for i in xrange(counts[8]):
		for c in ["E","I","G","H","T"]:
			s.remove(c)

	# print s

	# Second patch :1,3,5
	# Get 1
	counts[1] = s.count("O")
	for i in xrange(counts[1]):
		for c in ["O","N","E"]:
			s.remove(c)

	# Get 3
	counts[3] = s.count("R")
	for i in xrange(counts[3]):
		for c in ["T","H","R","E","E"]:
			s.remove(c)

	# Get 5
	counts[5] = s.count("F")
	for i in xrange(counts[5]):
		for c in ["F","I","V","E"]:
			s.remove(c)

	# print s

	# Second patch :7,9
	# Get 7
	counts[7] = s.count("V")
	for i in xrange(counts[7]):
		for c in ["S","E","V","E","N"]:
			s.remove(c)

	# Get 9
	counts[9] = s.count("I")
	for i in xrange(counts[9]):
		for c in ["N","I","N","E"]:
			s.remove(c)

	# print s

	return "".join([str(digit)*counts[digit] for digit in range(10)])

for i in range(n):
	s = list(raw_input())
	print "Case #" + str(i+1) + ": " + get_phone_number(s)