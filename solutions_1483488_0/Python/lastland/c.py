n = input()
for i in xrange(n):
    cnt = 0
    a, b = map(int, raw_input().split())
    for j in xrange(a, b):
	n = str(j)
	mem = {}
	for k in xrange(1, len(n)):
	    m = n[k:] + n[:k]
	    if int(n) < int(m) and int(m) <= b and m not in mem:
		mem[m] = 1
		cnt += 1
    print "Case #%d: %d" % (i + 1, cnt)
