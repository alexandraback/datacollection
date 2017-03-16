import sys

q = set("0123456789")
def f(n):
    if n == 0: return "INSOMNIA"
    a = set()
    copy = n
    for i in xrange(1000):
        a |= set(str(copy))
        if a == q: break
        copy += n
    return copy

total = None
count = 0
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	count += 1
	print "Case #%s: %s"%(count,f(int(line)))
	if count == total:
		break