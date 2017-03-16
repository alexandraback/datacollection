
f = open('/Users/Wanli/Downloads/B-large.in.txt')
# f = open('linput.txt')
ncases = int(f.readline())

for case in range(ncases):
	tokens = f.readline().split()
	a = int(tokens[0])
	b = int(tokens[1])
	k = int(tokens[2])
	if a > b:
		a, b = b, a

	if (a > k):
		total = (a + b - k) * k
	else:
		total = a * b

	for i in range(k, a):
		for j in range(k, b):
			if (i&j) < k:
				total += 1

	print 'Case #%d: %d' % (case+1, total)
