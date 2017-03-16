def next_switch(n):
	if n < 21:
		return 1
	if 91 <= n < 201:
		return 91
	s = str(n)
	if s[len(s)/2:] == len(s[len(s)/2:])*'0':
		s = str(n-1)
	m = len(s)/2
	big = s[:m]
	if len(s) % 2:	
		mid = s[m]
		small = s[m+1:]
	else:
		small = s[m:]
	if big == '1' + (len(big)-1)*'0':
		big = '9'*(len(big) - 1)
		if len(s) % 2:
			mid = '9'
	if small == '0'*len(small):
		small = '0'*(len(small)-2) + '1'
	else:
		small = '0'*(len(small) - 1) + '1'
	if len(s) % 2:
		nxt = int(big + mid + small)
	else:
		nxt = int(big + small)
	return nxt

def required_steps(N):
	count = 1
	while N != 1:
		nxt = next_switch(N)
		count += N - nxt + (nxt != 1)
		N = int(str(nxt)[::-1])
	return count



inF = open('A_large.in')
case_sols = []
for case in xrange(int(inF.readline())):
	N = int(inF.readline())
	case_sols.append(required_steps(N))

inF.close()

A_sol = open('A_large_sol.txt', 'w')
for i, sol in enumerate(case_sols):
	A_sol.write('Case #{0}: '.format(i+1) + str(sol) + '\n')

A_sol.close()
