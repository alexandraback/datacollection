import sys
T=input();
for t in range(0,T):
	K,C,S=map(int,sys.stdin.readline().split());
	out=[];
	next=0;
	while(next<K):
		id=0;
		for j in range(0,C):
			id=id*K+next%K;
			next+=1;
		out.append(id+1);
	ans="Case #"+str(t+1)+":"
	if(len(out)<=S):
		for w in out:
			ans+=" "+str(w);
	else :
		ans+=" IMPOSSIBLE";
	print ans;
		