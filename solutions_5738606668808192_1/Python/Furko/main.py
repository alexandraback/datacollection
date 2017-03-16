from __future__ import print_function
def prime(n):
	if n == 0 or n == 1:
		return -1
	i = 2
	for x in range(2, 10000):
		if n % x == 0:
			return x
	return -1 

def bit(mask, x):
	mask &= 2 ** x
	if mask > 0:
		return True
	return False

t = 1
n = 32
cnt = 500
ans = []
for M in range(5000):
	cur = 1 + 2 * M + (2 ** 31)
	was = False
	for d in range(2, 11):
		pw = 1
		nd = 0
		for it in range(n):
			if bit(cur, it) == True:
				nd += pw
			pw *= d
		if prime(nd) == -1:
			was = True
			break
	if was == False:
		ans.append(cur)
		if len(ans) == cnt:
			break
if len(ans) != cnt:
	print ("FUCK")
	exit(0)
for it in range(500):
	x = ans[it]
	for i in range(n-1, -1, -1):
		t = 0
		if bit(x, i):
			t = 1
		print (t, end = "")
	for d in range(2, 11):
		pw = 1
		nd = 0
		for it2 in range(n):
			if bit(x, it2) == True:
				nd += pw
			pw *= d
		print (' ',prime(nd), sep="",end="")
	print()
