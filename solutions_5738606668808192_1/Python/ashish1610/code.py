def isPrime(n):
	fact = -1;
	cnt = 0
	for i in xrange(2, (int)(n ** 0.5) + 1):
		cnt += 1
		if n % i == 0:
			fact = i
			break
		if cnt == 10:
			break
	if fact == -1:
		return (True, -1)
	else:
		return (False, fact)
t = input()
n, j = map(int, raw_input().split())
st = (1 << (n - 1)) + 1
v = []
for mask in xrange(st, (1 << n), 2):
	ar = []
	tmp = mask
	while tmp:
		ar.append(tmp % 2)
		tmp /= 2
	ar.reverse()
	base_val = []
	for base in range(2, 11):
		val = 0
		for i in range(len(ar)):
			val = val * base + ar[i]
		base_val.append(val)
	flag = True
	st = []
	for i in range(len(base_val)):
		tmp = isPrime(base_val[i])
		if tmp[0]:
			flag = False
			break
		else:
			st.append(tmp[1])
	if flag:
		v.append((ar, st))
	if len(v) == j:
		break
print "Case #1:"
for i in xrange(j):
	print "".join([str(x) for x in v[i][0]]),
	print " ".join([str(x) for x in v[i][1]])