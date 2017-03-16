# Dancing with the Googlers

def solve(n, s, p, t):
	not_surprising = []
	surprising = []
	for i in range(n):
		if t[i] % 3 == 0:
			not_surprising.append(t[i]/3)
			if t[i] >= 3: surprising.append(t[i]/3+1)
			else: surprising.append(t[i]/3)
		elif t[i] % 3 == 1:
			not_surprising.append((t[i]+2)/3)
			if t[i] >= 4: surprising.append((t[i]+2)/3)
			else: surprising.append((t[i]+2)/3)
		else:	
			not_surprising.append((t[i]+1)/3)
			surprising.append((t[i]+4)/3)
	if s == n: 
		return sum(map(lambda x: x >= p, surprising))
	elif s < n:
		ans = 0
		not_s_best = [i for i in range(n) if not_surprising[i] >= p]
		not_s_not_best = [i for i in range(n) if not_surprising[i] < p]
		s_best = [i for i in not_s_not_best if surprising[i] >= p]
		ans += min(s, len(s_best)) + len(not_s_best)
		return ans
			

T = int(raw_input())
for t in range(T):
	inp = map(int, raw_input().split())
	assert len(inp) == inp[0]+3 
	n, s, p = inp[0:3]
	inp = inp[3:]
	print 'Case #%d: %d' %(t+1, solve(n,s,p,inp)),
	if t < T-1: print
	