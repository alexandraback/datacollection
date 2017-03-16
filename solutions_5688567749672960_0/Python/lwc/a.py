def rev(n):
	return int(''.join(list(reversed(n)))) 


def f(n):
	rtn = 0
	if n < 20:
		return n
	ss = str(n)
	ck = 0
	i = 10
	while i <= n:
		sz = len(str(i-1)) / 2
		qq = 10**sz-1
		rtn += i-rev(str(i/10 + qq)) + qq + 1
		if i == n:
			return rtn
		i *= 10
	if int(ss[len(ss)/2:]) == 0:
		ss = str(n-1)
		rtn += 1
	rv = rev(ss[0:len(ss)/2])
	if rv != 1:
		rtn += rv + int(ss[len(ss)/2:])
	else:
		rtn += int(ss[len(ss)/2:])
	return rtn


t = int(raw_input())
for i in range(t):
	n = int(raw_input())
	print ('Case #%d: ' % (i+1)) + str(f(n))
	

