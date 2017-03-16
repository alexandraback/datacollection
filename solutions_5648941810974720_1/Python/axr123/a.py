import sys

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
keys   = {"Z" : 0, "W" : 2 , "U" : 4 , "X" : 6, "G" : 8 }

def update(s, digit):
	# and remove letters
	for dc in digits[digit]:
		for i in range(len(s)):
			if s[i] == dc:
				s[i] = ' '
				break

numcases = int(sys.stdin.readline())
for _c in range(numcases):
	count  = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	s = [x for x in sys.stdin.readline()]
	s = s[:-1]
	# first pass: eliminate non-ambiguous ones
	for c in s:
		if c in keys:
			# count digit
			count[keys[c]] += 1
			update(s, keys[c])
	# now look for FIVE: F is key
	for c in s:
		if c == 'F':
			count[5] += 1
			update(s, 5)
	# NINE: I
	for c in s:
		if c == 'I':
			count[9] += 1
			update(s, 9)
	# SEVEN: S
	for c in s:
		if c == 'S':
			count[7] += 1
			update(s, 7)
	# ONE: O
	for c in s:
		if c == 'O':
			count[1] += 1
			update(s, 1)
	# THREE: T
	for c in s:
		if c == 'T':
			count[3] += 1
			update(s, 3)
	# now all should be replaced
	for c in s:
		assert(c == ' ')
		
	# output
	s = ""
	for i in range(10):
		for j in range(count[i]): s += str(i)
	print("Case #%d: %s" % (_c+1, s))