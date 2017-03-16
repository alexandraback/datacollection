def shift(x):
	return x[-1]+x[:-1]

def solve():
	A,B = map(int,raw_input().split())
	res=0
	for n in range(A,B+1):
		m = str(n)
		while True:
			m = shift(m)
			if int(m) == n: break
			if n < int(m) <= B:
				res+=1
	return res

t = input()
for testcase in range(t):
	print "Case #%d: %d" %(testcase+1, solve())

