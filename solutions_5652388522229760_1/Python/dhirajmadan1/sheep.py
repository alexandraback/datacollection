def decdig(i):
	ret=dict();
	while(not(i==0)):
		d=i%10;
		i=i/10;
		if(not(ret.has_key(d))):
			ret[d]=True;	
	return ret;		

ans=[];
T=input();
for i in range(T):
	N=input();
	if(N==0):
		ans.append(0);
		continue;
	cur=N;
	digs=dict();
	while(not(len(digs.keys())==10)):
		r=decdig(cur);
		for d in r.keys():
			digs[d]=True;
		cur=cur+N;
	ans.append(cur-N);

for i in range(T):
	if(ans[i]>0):
		print("Case #"+str(i+1)+": "+str(ans[i]));
	else:
		print("Case #"+str(i+1)+": INSOMNIA");