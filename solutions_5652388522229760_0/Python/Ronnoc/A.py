IN = open("A.in","r");
OUT= open("A.out","w");
T=int(IN.readline());
for t in range(0,T):
	N=int(IN.readline());
	vis=[];
	for i in range(0,10):
		vis.append(0);
	OUT.write("Case #"+str(t+1)+": ");
	if N==0 :
		OUT.write("INSOMNIA\n");
	else :
		now=0;
		rem=10;
		while(rem>0):
			now+=N;
			tmp=now;
			while(tmp>0):
				x=tmp%10;
				tmp/=10;
				if(vis[x]==0):
					vis[x]=1;
					rem-=1;
		OUT.write(str(now)+"\n");
IN.close();
OUT.close();