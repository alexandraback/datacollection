n = int(raw_input())
f = lambda n,r:(2*(n+r)-1)*n
for cas in range(1,n+1):
	r,t = map(int,raw_input().split())
	ll = 0
	rr = t
	while ll+1<rr :
		mm = (ll+rr)/2
		if f(mm,r)<=t:
			ll=mm
		else:
			rr=mm
	print "Case #%d:" % cas,ll

