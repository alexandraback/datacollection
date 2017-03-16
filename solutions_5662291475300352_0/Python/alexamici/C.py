for tc in range(input()):
	N=input()
	HG=[map(int,raw_input().split())for n in range(N)]
	H=[(D,M+h)for D,H,M in HG for h in range(H)]
	res=0
	if len(H)>1:
		try:
			F,S=H
		except:
			continue
		if F[1]>S[1]:
			F,S=S,F
		t2=360*F[1]+F[1]*(360-F[0])
		s1=S[1]*(360-S[0])
		if s1>=t2:
			res=1
	print'Case #{}: {}'.format(tc+1,res)