from collections import Counter 

dig = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
cts = []
for i in xrange(10):
	cts.append(Counter(dig[i]))

def solve(S):
	ct = Counter(S)
	final = [ct['Z'], -1, ct['W'], -1, ct['U'], -1, ct['X'], -1, ct['G'], -1]
	for i in xrange(10):
		if final[i] != -1:
			for c in cts[i]:
				ct[c] -= final[i] * cts[i][c]
	final[1] = ct['O']
	for c in cts[1]:
		ct[c] -= final[1] * cts[1][c]
	final[3] = ct['H']
	for c in cts[3]:
		ct[c] -= final[3] * cts[3][c]
	final[5] = ct['F']
	for c in cts[5]:
		ct[c] -= final[5] * cts[5][c]
	final[7] = ct['V']
	for c in cts[7]:
		ct[c] -= final[7] * cts[7][c]
	final[9] = ct['I']
	num = []
	for i in xrange(10):
		num.extend(final[i] * [i])	
	return ''.join(map(str, num))


T = int(raw_input())
for case in range(1, T+1):
	S = raw_input()
	print "Case #{}: {}".format(case, str(solve(S)))