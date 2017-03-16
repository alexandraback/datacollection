def begin(c, sb):
	s_copy = sb.lstrip(c)
	if len(s_copy) == 0:
		return True
	if ord(c) != ord(s_copy[0]):
		return ord(c) > ord(s_copy[0])

def solve(s):
	new_word = ""
	for c in s:
		if begin(c, new_word):
			new_word = c + new_word
		else:
			new_word = new_word + c
	return new_word



n = int(input())

for i in range(n):
	print(("Case #%d: " % (i+1)) + str(solve(input()))) #i