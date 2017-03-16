n = input()
for i in xrange(n):
    cnt = 0
    p = map(int, raw_input().split(" "))
    for j in xrange(3, len(p)):
	a = p[j] / 3
	b = (p[j] - a) / 2
	c = p[j] - a - b
	if max(a, b, c) < p[2]:
	    if max(a, b, c) + 1 < p[2] or p[1] <= 0: continue
	    maxa = max(a, b, c)
	    a = maxa + 1
	    b = (p[j] - a) / 2
	    c = p[j] - a - b
	    if a - min(b, c) == 2 and min(b, c) >= 0:
		cnt += 1
		p[1] -= 1
	else:
	    cnt += 1
    print "Case #%d: %d" % (i + 1, cnt)
