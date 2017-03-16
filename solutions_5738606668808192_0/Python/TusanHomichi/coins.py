def base(s,n):
	ret = 0
	for c in s:
		ret *= n
		if c == "1":
			ret += 1
	return ret

def isPrime(n):
	if n == 1:
		return None
	if n == 2:
		return None
	if n%2 == 0:
		return 2
	d = 3
	while d*d <= n:
		if n%d == 0:
			return d
		d += 2
	return None

def is_coin(n):
	s = bin(n)[2:]
	witnesses = []
	for b in range(2,11):
		w = isPrime(base(s,b))
		if not w:
			return None
		witnesses.append(w)
	return witnesses

def find_coins(n,j):
	i = 2**(n-1)+1
	found = 0
	while found < j:
		w = is_coin(i)
		if w:
			print bin(i)[2:] + " " + " ".join(map(str,w))
			found += 1
		i += 2
		
T = raw_input()
N,J = map(int,raw_input().split(" "))

print "Case #1:"
find_coins(N,J)