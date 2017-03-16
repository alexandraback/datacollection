import sys
def isnp(x):
	j=2;
	while(j*j<=x):
		if(x%j==0):
			return j;
		j+=1;
	return 0;

T=input();
for t in range(0,T):
	print "Case #"+str(t+1)+":"
	N , J = map(int,sys.stdin.readline().split())  
	for i in range(0,1<<(N-2)):
		if(J==0):
			break;
		x=1<<(N-1)|i<<1|1;
		os='';
		for j in range(0,N)[::-1]:
			os+=str(x>>j&1);
		fail=0;
		out="";
		for k in range(2,11):
			x=int(os,k);
			y=isnp(x);
			if(y==0):
				fail=1;
				break;
			else :
				out+=" "+str(y);
		if(fail==0):
			J-=1;
			print os+out;