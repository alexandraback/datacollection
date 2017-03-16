import sys
def f(k,c,s):
	step = 0
	for _ in xrange(c):
		step += k**_
	nums = []
	i = 1
	for j in xrange(k):
		nums.append(i)
		i += step
	return ' '.join(map(str,nums))

count = 0
total = None
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	count += 1
	print "Case #%s: %s"%(count,f(*map(int, line.split(' '))))
	if count == total:
		break