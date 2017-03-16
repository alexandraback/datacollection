import math




def main():
	f = open('input.txt')
	T = int(f.readline())
	for tt in range(1, T + 1):
		ll = map(int, f.readline().split())
		cur = ll[0]
		n = ll[1]
		aa = map(int, f.readline().split())
		aa = sorted(aa)
		if cur == 1:
			ans = n
		else:
			ans = 10000000000
			tmp = 0
			for i in range(n):
				if tmp + n - i < ans:
					ans = tmp + n - i
				if cur > aa[i]:
					cur += aa[i]
				else:
					while cur <= aa[i]:
						cur = cur * 2 - 1
						tmp += 1
					cur += aa[i]
			if tmp < ans:
				ans = tmp

		print "Case #%d: %d" % (tt, ans)	

	


main()
