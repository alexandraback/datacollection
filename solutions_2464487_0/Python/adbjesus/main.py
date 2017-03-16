T = input()

for i in range(1,T+1):
	s=raw_input().split()
	r=long(s[0])+1;
	t=long(s[1]);
	k = 0
	while(True):
		tmp = (r*r)-((r-1)*(r-1))
		if(tmp>t):
			break
		k=k+1
		t=t-tmp
		r=r+2
	print "Case #"+str(i)+": "+str(k)

