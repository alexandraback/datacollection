def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)

def main():
	t = int(raw_input())
	for case in range(1, t+1):
		a,b = map(int, raw_input().split('/'))
		c = gcd(a, b)
		a = a//c
		b = b//c

		tmp = b
		flag = 0
		while tmp:
			if tmp&1 and not(tmp==1):
				flag = 1
				break
			tmp = tmp>>1

		if flag == 1:
			print "Case #%d: impossible"%case
			continue

		cnt = 0
		val = float(a)/float(b)
		while val<1.0:
			val = val*2.0
			cnt += 1
			if val > 1.0:
				break
		print "Case #%d: %d"%(case,cnt)

main()
