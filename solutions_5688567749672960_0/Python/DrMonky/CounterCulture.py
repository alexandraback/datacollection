fi = open('A-small-attempt0.in', 'r')
fo = open('output', 'w')

T = int(fi.readline())
def swap(n):
	swap_n = int(str(n)[::-1])
	if (len(str(int(swap_n))) == len (str(n))):
		if swap_n < n:
			return swap_n
		else:
			return None	
	else:
		return None

for test in range(T):
	n = int(fi.readline())
	count = 1
	dp = [0]
	for i in range(1,n+1):
		if swap(i):
			dp.append(min(dp[i-1], dp[swap(i)]) + 1)
		else:
			dp.append(dp[i-1] + 1)
	fo.write("Case #%i: %i\n" % (test+1, dp[-1]))