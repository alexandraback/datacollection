

def solve(S):
	words = []
	words.append(S[0])
	for i in S[1:]:
		if i >= words[0]:
			words.insert(0,i)
		else:
			words.append(i)

	return ''.join(words)



for t in xrange(1, input()+1):
	S = raw_input()
	print "Case #{0}: {1}".format(t, solve(S))