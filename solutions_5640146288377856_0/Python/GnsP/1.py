T=int(input())
for tc in range(1,T+1):
	[r,c,w]=[int(x) for x in input().split()]
	s=(r-1)*(c//w)
	if c//w==1:
		if c==w:
			s=s+w
		else:
			s=s+w+1
	else:
		if c%w==0:
			s=s+c//w+w-1
		else:
			s=s+c//w+w
	print('Case #{_tc}: {_s}'.format(_tc=tc,_s=s))
