def get_primes(n):
	is_prime = [True for i in range(n+1)]
	i = 2
	while i * i <= n:
		for j in range(2*i, n+1, i):
			is_prime[j] = False
		i += 1
	return [i for i in range(2, n+1) if is_prime[i]]

BASES = range(2,11)
MAX_PRIME = 100 # no need to identify all composite numbers
PRIMES = get_primes(MAX_PRIME)

def base(arr, b):
	return sum([b**i * arr[i] for i in range(len(arr))])

def divisor(n):
	for p in PRIMES:
		if n % p == 0:
			return p
	return 1 

def jam_coin_proof(arr):
	proof = []
	for b in BASES:
		dv = divisor(base(arr, b))
		if dv == 1:
			return False
		proof.append(dv)
	return proof

def mutate_coin(coin):
	i = 1
	while coin[i] == 1:
		coin[i] = 0
		i += 1
	coin[i] = 1

def get_jam_coins(N, J):
	coin = [1] + [0 for i in range(N-2)] + [1]
	jam_coins = []
	while len(jam_coins) < J:
		proof = jam_coin_proof(coin)
		if proof:
			jam_coins.append(''.join(map(str, coin[::-1])) + ' ' + ' '.join(map(str, proof)))
		mutate_coin(coin)
	return jam_coins

def solve(N, J):
	return '\n' + '\n'.join(get_jam_coins(N, J))


T = int(raw_input())
for case in range(1, T+1):
	N, J = map(int, raw_input().split())
	print "Case #{}: {}".format(case, str(solve(N, J)))