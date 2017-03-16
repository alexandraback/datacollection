from collections import Counter 

dig = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
cts = []
for i in xrange(10):
	cts.append(Counter(dig[i]))

def solve(S):
	ct = Counter(S)
	num = []
	cur = 0
	while ct:
		if cur == 10:
			while cur > num[-1]:
				cur -= 1
		c = cts[cur]
		if num and num[-1] == cur:
			num.pop()
			ct += c
		else:
			mn = 10000
			for k in c:
				mn = min(mn, ct[k]/c[k])
			for _ in xrange(mn):
				ct -= c
				num.append(cur)
		cur += 1
	return ''.join(map(str, num))


T = int(raw_input())
for case in range(1, T+1):
	S = raw_input()
	print "Case #{}: {}".format(case, str(solve(S)))