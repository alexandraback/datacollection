import sys

def mul(x, y): #(a1, b1, c1, d1), (a2, b2, c2, d2)
	return (x[0] * y[0] - x[1] * y[1] - x[2] * y[2] - x[3] * y[3],
			x[0] * y[1] + x[1] * y[0] + x[2] * y[3] - x[3] * y[2],
			x[0] * y[2] - x[1] * y[3] + x[2] * y[0] + x[3] * y[1],
			x[0] * y[3] + x[1] * y[2] - x[2] * y[1] + x[3] * y[0])

def m(x):
	return (-x[0], -x[1], -x[2], -x[3])

def equ(x, y):
	return x[0] == y[0] and x[1] == y[1] and x[2] == y[2] and x[3] == y[3]
	
def inv(x):
	return (x[0], -x[1], -x[2], -x[3])

o = (1, 0, 0, 0)
i = (0, 1, 0, 0)
j = (0, 0, 1, 0)
k = (0, 0, 0, 1)

t = int(input())

conv = {'i' : i, 'j' : j, 'k' : k}

for testNo in range(1, t + 1):
	print("testNo = " + str(testNo), file = sys.stderr)
	ans = True
	[n, x] = [int(chunk) for chunk in input().split(' ')]
	if x > 8:
		x = 8 + (x % 4)
	s = [conv[c] for c in input() * x]
	
	prod = o

	for x in s:
		prod = mul(prod, x)
	
	if prod != mul(mul(i, j), k):
		ans = False
	
	firstI = len(s) + 10
	firstK = -10
	
	l = o
	for pos in range(len(s)):
		l = mul(l, s[pos])
		if l == i:
			firstI = pos
			break
	
	s = s[::-1]
	l = o
	for pos in range(len(s)):
		l = inv(mul(inv(l), inv(s[pos])))
		if l == k:
			firstK = pos
			break
	
	if firstI >= len(s) - firstK:
		ans = False
	#print(firstI)
	#print(firstK)
	
	if ans:
		ans = "YES"
	else:
		ans = "NO"
	
	print("Case #" + str(testNo) + ": " + ans)

	


