def getr(x, base):
	v = []
	while (x):
		v.append(x % base)
		x //= base
	v = v[::-1]
	return v

def getv(v):
	p = 1
	res = 0
	for x in range(len(v))[::-1]:
		res += p * v[x]
		p *= 10
	return res

ans = []

def f(v, t):
	v = copy(v, t)	
	x = getv(v)
	ans.append(x * x)

def copy(v, t):
	if (t == 2):
		v2 = v[:-1]
		return v + v2[::-1]
	else:
		return v + v[::-1]

def check(m, R, t):
	v = getr(m, 2)
	v = copy(v, t)
	j = getv(v)
	return (j * j <= R)

def bin_search(R, t):
	l = 1
	#r = 1000000000000000000000000000
	r = 10000000000000000	
	while (l < r):
		m = (l + r) // 2
		if (check(m, R, t)):
			l = m + 1
		else:
			r = m
	if (not check(l, R, t)):
		l -= 1
	return l

def proc_1_2(n):
	v = [1]
	for x in range(n):
		v.append(0)
	v.append(2)
	f(v, 2)
	for x in range(n):
		v[x + 1] = 1
		f(v, 2)
		v[x + 1] = 0

def proc_2_01(n):
	v = [2]
	f(v, 2)
	f(v, 1)
	for i in range(n):
		f(v + [0], 2)
		f(v + [1], 2)
		f(v + [0], 1)
		v.append(0) 

ans.append(9)

def solve(R):
	res = bin_search(R, 1) + bin_search(R, 2)
	for x in ans:
		if x <= R:
			res += 1
	return res

for x in range(10):
	proc_1_2(x)
proc_2_01(10)

print(len(ans))

R = 0
FIN = open('input.txt')
FOUT = open('output.txt', 'w')
t = int(FIN.readline())
for it in range(t):
	#print it
	l, r = map(int, FIN.readline().split())
	FOUT.write("Case #" + str(it + 1) + ": " + str(solve(r) - solve(l - 1)) + "\n")

