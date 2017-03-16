T = int(raw_input())
N,J = map(int, raw_input().split(' '))

def change_base (N, base):
	ans = 0
	order = 1
	while (N > 0):
		ans += order*(N%10)
		order *= base
		N = N/10
	return ans


def nontrivial_divisor(N): # if not prime, return a nontrivial divisor; if prime, return 0
	if (N == 2 or N == 3):
		return 0
	if (N % 2 == 0):
		return 2
	if (N % 3 == 0):
		return 3
	i = 5
	step = 2
	while (i*i <= N):
		if (N % i == 0):
			return i
		i += step
		step = 6 - step
	return 0

#print nontrivial_divisor(77)

def legit(N): # N is represented in base 2
	ans = []
	for base in range(2, 11):
		temp = change_base(N,base)
		divisor = nontrivial_divisor(temp)
		if (divisor == 0):
			return '#'
		else:
			ans.append(divisor)
	return ' '.join(str(i) for i in ans)

def next_binary(x): # x is a string of a binary number
	i = x.rfind('0')
	if (i != -1):
		y = x[0:i]+ '1'+'0'*(len(x)-i-1)
	else: 
		y = '1'+ '0'*(len(x))
	return y

#print next_binary ('1111')

for case in range(1, T+1):
	print "Case #{}:".format(case)
	count = 0
	x = '0'*(N-2)
	while (count < J):
		x = next_binary(x)
		y = '1'+x+'1'
		s = legit(int(y))
		if (s != '#'):
			print y, s
			count+= 1

	