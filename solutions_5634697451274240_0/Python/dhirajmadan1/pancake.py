def count(s):
	if(s[0]=='-'):
		cur=1;
	else:
		cur=0;
	sym=s[0];	
	for i in range(1,len(s)):
		if((sym=='+')and(s[i]=='-')):
			cur=cur+2;
		sym=s[i];	
	return cur;

T=input();
ans=[0]*T;
for i in range(T):
	s=raw_input();
	ans[i]=count(s);

for i in range(T):
	print("Case #"+str(i+1)+": "+str(ans[i]));




		

