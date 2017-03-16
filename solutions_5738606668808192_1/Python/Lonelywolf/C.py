import sys

def print_ans(case_num):
	print('Case #%d:' % case_num)


def small(N):
	return int('1'+'0'*(N-2)+'1', 2)


def large(N):
	return int('1'+'1'*(N-2)+'1', 2)


def bin_str(num):
	return bin(num)[2:]



def check_divisor_is_valid(num, div):
	if int(num / div) < div : return False
	else : return True


def divisor(num, primes):
	ret = 0;
	for i in primes:
		if num % i == 0: return i
	return ret

def algorithm(num_str, primes):
	ans = []
	for i in range(2, 11):
		div = divisor(int(num_str, i), primes)
		if div != 0 : ans.append(div)
		else : break
	
	return ans


primes = set([3])

for i in range(4, 10000) : 
	check = True
	for p in primes:
		if i % p == 0:
			check = False
			break
	if check:
		primes.add(i)

T = int(sys.stdin.readline())
N, J = sys.stdin.readline().split()
sm = small(int(N))
lg = large(int(N))

r = int((lg -sm) / 2) + 1

print_ans(1)
cnt = 0
for i in range(r):
	binstr = bin_str(sm + (2*i))
	ans = algorithm(binstr, primes)
	if len(ans) == 9 :
		print(binstr, " ".join([str(x) for x in ans]))
		cnt += 1
	
	if cnt == int(J) : break