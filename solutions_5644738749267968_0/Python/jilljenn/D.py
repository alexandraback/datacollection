from bisect import bisect_left

T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	naomi = map(float, raw_input().split())
	ken = map(float, raw_input().split())
	a = sorted(naomi)
	b = sorted(ken)
	# dw = max(sum(a[k + i] > b[k] for i in range(N - k)) for k in range(N)) # This is not gonna work xD
	dw = 0
	da = [i for i in a]
	db = [i for i in b]
	for k in a:
		if k > db[0]:
			dw += 1
			db.pop(0)
		else:
			db.pop()
	w = 0
	for k in a:
		i = bisect_left(b, k)
		if i == len(b):
			w += 1
			b.pop(0)
		else:
			b.pop(i)
	print 'Case #%d: %d %d' % (t + 1, dw, w)
