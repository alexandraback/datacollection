t = int(raw_input())
for case in range(t):
    a,b,k = raw_input().split(' ')
    a,b,k = int(a), int(b), int(k)
    count = 0
    for i in range(a):
	for j in range(b):
	    if i&j < k:
		count += 1
    print 'Case #%d: %d' % (case+1, count)
