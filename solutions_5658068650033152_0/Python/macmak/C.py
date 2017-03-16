T = int(raw_input())

for case in xrange(T):
	N,M,K = map(int,raw_input().strip().split())
	
	if N>=M:
		w = N
		h = M
	else:
		w = M
		h = N
	
	if h<=2:
		print 'Case #'+str(case+1)+':',K
		continue
	
	if K <= 3:
		print 'Case #'+str(case+1)+':',K
		continue
	
	rh = 3
	rw = 3
	encl = 5
	used = 4
	
	while encl < K:
		if encl+1 == K:
			used+=1
			encl+=1
			continue
		if rh<h:
			rh+=1
			used+=2
			encl+=rw
			continue
		if rw<w:
			rw+=1
			used+=2
			encl+=rh
			continue
		encl+=1
		used+=1
		
	print 'Case #'+str(case+1)+':',used
	