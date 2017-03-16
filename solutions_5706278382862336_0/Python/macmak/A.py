T = int(raw_input())

for case in xrange(T):
	P,Q = map(int,raw_input().strip().split('/'))
		
	if P == Q:
		print 'Case #'+str(case+1)+': 0'
		continue
	if P == 0:
		print 'Case #'+str(case+1)+': impossible'
		continue
	
	powden = 0
	den = Q
	while den%2 == 0:
		powden+=1
		den/=2
	
	if P%den != 0:
		print 'Case #'+str(case+1)+': impossible'
		continue
	
	P/=den
	
	pownum = 0
	num = 1
	while num*2 <= P:
		pownum+=1
		num*=2
	
	print 'Case #'+str(case+1)+':',powden-pownum