from sys import stdin
def rline():
	return stdin.readline().rstrip()

for i in range(int(rline())):
	data = map(int, rline().split())
	googlers = data[0]
	surprising = data[1]
	p = data[2]
	scores = data[3:]
	num = 0
	for score in scores:
		if score == 0 and p > 0:
			pass
		elif score >= 3*p - 2:
			num += 1
		elif (score == 3*p - 3 or score == 3*p - 4) and surprising > 0:
			surprising -= 1
			num += 1
	print "Case #%s: %s" % (i+1, num)

