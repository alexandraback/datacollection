import random

T = int(raw_input())

def change_base (N, base): # change a number from base base to base 10
	ans = 0
	order = 1
	while (N > 0):
		ans += order*(N%10)
		order *= base
		N = N/10
	return ans



def base_2 (N): # change a number from base 10 to base 2, return a string
	ans = ''
	while (N > 0):
		ans = str(N % 2) + ans
		N = N/2
	return ans


def composite_test(N): # test a number N > 1 is composite or not. It's 100% true if the number is composite
	for i in range(3):
		rand_number = random.randint(1, N-1)
		if (pow(rand_number, N-1, N) != 1):
			return True
	return False

def nontrivial_divisor(N): # given N composite, find a nontrivial divisor of N which is smaller than 1000. return 0 if cannot find it
	if (N % 2 == 0):
		return 2
	if (N % 3 == 0):
		return 3
	i = 5
	step = 2
	while (i <= 1000):
		if (N % i == 0):
			return i
		i += step
		step = 6 - step
	return 0


def legit(N): # N is represented in base 2
	ans = []
	l = []
	for base in range(2, 11):
		temp = change_base(N,base)
		l.append(temp)
		flag = composite_test(temp)
		if (flag == False): # if not sure temp is composite or not, skip it and return
			return '#'
	for i in range(9):
		temp = l[i]
		divisor = nontrivial_divisor(temp)
		if (divisor == 0): # cannot find a divisor < 1000, skip it and return
			return '#'
		ans.append(divisor)
	return ' '.join(str(i) for i in ans) # return a string of 9 nontrivial divisors

	

def run():
	for case in range(1, T+1):
		dic = []
		N,J = map(int, raw_input().split(' '))
		print "Case #{}:".format(case)
		count = 0
		while (count < J):
			x = random.randint(0, 2**(N-2)-1)
			temp = base_2(x)
			temp = '0'*(N-2-len(temp)) + temp
			y = '1'+temp+'1' # get a string representing a jamcoin
			s = legit(int(y)) # check if it's legit
			if (s != '#' and y not in dic): # if it's legit then print it
				dic.append(y)
				print y, s
				count+= 1

run()



					