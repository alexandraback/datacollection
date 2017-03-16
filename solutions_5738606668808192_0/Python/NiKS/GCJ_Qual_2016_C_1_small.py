from fractions import gcd

MAXF = 1000

N = 16
J = 50

M = 1
j_cnt = 0

def f(x):
	return (x*x+1)%M

def factorize(n):
	global M
	M = n
	for ft in range(2, 32):
		if n%ft==0:
			return ft
		if(ft*ft>n):
			return 1
	x = 2
	y = x
	g = 1
	cnt = 33
	while g==1:
		x = f(x)
		y  = f(f(y))
		g = gcd(abs(x-y), n)
		if(n%cnt==0):
			return cnt
		cnt+=2
		if(cnt>MAXF):
			return 1
	if(g!=n):
		return g
	return 1


print("Case #1:")
for m in range(0, 1<<(N-2)):
	s = bin((1<<(N-1))+(m<<1)+1)[2:]
	factors = [0, 0, 0, 0, 0, 0, 0, 0, 0]
	is_valid = True
	for b in range(2, 11):
		v = int(s, b)
		factors[b-2] = factorize(v)
		if factors[b-2] == 1:
			is_valid = False
			break
	if is_valid:
		j_cnt += 1
		print(v, end='')
		for fact in factors:
			print(" "+str(fact), end='')
		print('')
	if j_cnt==J:
		break
#if j_cnt!=J:
#	print("Error: Only "+str(j_cnt)+" elements found")
