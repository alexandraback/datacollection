import sys

def getToPower(exponent):
	ans = 0
	for i in range(exponent):
		ans += 10 ** (int((i + 1)/2)) + 10 ** int((i + 2)/2) - 1
	return ans

def main():
	T = int(sys.stdin.readline())
	for i in range(T):
		N = sys.stdin.readline()[:-1]
		if (len(N) == 1):
			print "Case #%d: %s" % (i + 1, N)
			continue
		ans = getToPower(len(N) - 1)
		if (N.rstrip('0') == '1'):
			print "Case #%d: %d" % (i + 1, ans)
			continue
		if (N[len(N)/2:].rstrip('0') == ''):
			N = str(int(N) - 1)
			ans += 1
		if (N[0:len(N)/2].rstrip('0') == '1'):
			ans += int(N[len(N)/2:])
			print "Case #%d: %d" % (i + 1, ans)
			continue
		ans += int(N[0:len(N)/2][::-1])
		ans += int(N[len(N)/2:])
		print "Case #%d: %d" % (i + 1, ans)

main()