T = int(raw_input())

def wordify(word, K):
	out = 0
	while word:
		out *= K
		out += word.pop()
	return str(out+1)

def doprob():
	read = raw_input()
	K, C, S = read.split()
	K = int(K)
	C = int(C)
	S = int(S)
	if S*C < K:
		return "IMPOSSIBLE"
	else:
		out = ""
		current = 0
		word = []
		while current < K:
			for i in xrange(C):
				word.append(min(current, K-1))
				current += 1
			out += wordify(word, K) + " "
	return out

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())