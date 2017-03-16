inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())
c = 0
for i in range(t):
	ans = 0
	a, b = map(str, inf.readline().split())
	c = int(b[0])
	for j in range(1, len(b)):
		if c < j:
			ans += j - c
			c = j
		c += int(b[j])
	print('Case #', end = '', file = ouf)
	print(i + 1, end = '', file = ouf)
	print(':', end = ' ', file = ouf)
	print(ans, file = ouf)

inf.close()
ouf.close()


