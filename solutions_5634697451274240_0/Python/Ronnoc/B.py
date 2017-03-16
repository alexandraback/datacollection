IN = open("B.in","r");
OUT= open("B.out","w");
T=int(IN.readline());
for t in range(0,T):
	s=IN.readline();
	s=s[::-1];
	ans=0;
	cnt=0;
	for c in s [1::]:
		if c=='+':
			x=0;
		else :
			x=1;
		x+=cnt;
		x%=2;
		ans+=x;
		cnt+=x;
	OUT.write("Case #"+str(t+1)+": "+str(ans)+"\n");
IN.close();
OUT.close();