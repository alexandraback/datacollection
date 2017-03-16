import io
import math
import time

def sieve_prime(n) :
	primes = []
	flag = [True for _ in range(n)]
	flag[0] = flag[1] = False
	for ii in range(2, n) :
		if flag[ii] == True :
			primes.append(ii)
			for jj in range(ii*2, n, ii) :
				flag[jj] = False
	return primes

def b10tobx(dec, x) :
	ans = 0
	ii = 0
	while dec > 0 :
		ans += (dec % x)*(10**ii)
		dec /= x
		ii += 1
	return ans

def b2tobx(bin, x) :
	ans = 0
	ii = 0
	while bin > 0 :
		ans += (bin % 10) * (x**ii)
		bin /= 10
		ii += 1
	return ans
	
lprimes = sieve_prime(10**7)

def find_factor(x) :
	slim = int(math.sqrt(x)+1)
	ii = 0
	for ii in range(len(lprimes)) : 
		if x % lprimes[ii] == 0 :
			return lprimes[ii]
		ii+=1
	return -1

if __name__ == '__main__' :
	#stime = time.time()
	T = int(raw_input())
	N, J = map(int, raw_input().split())
	
	curr = 2**(N-1)+1 # 1...0N...1
	print "Case #1: "
	while J > 0 :
		arr = []
		is_valid = True
		for bb in range(2, 11) :
			curr_bb = b2tobx(b10tobx(curr, 2), bb)
			curr_bb_factor = find_factor(curr_bb)
			if curr_bb_factor == -1 :
				is_valid = False
				break
			else :
				arr.append(curr_bb_factor)
		if is_valid :
			print "{} {}".format(b10tobx(curr, 2), ' '.join(map(str, arr)))
			J -= 1
		curr += 2
		pass
	#print time.time() - stime;
	pass
