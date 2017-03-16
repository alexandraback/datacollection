import math;
T=input();
ans=[[]]*T;
def getNextInt(C,K,i):#Gives an integer for base K repr of iC to iC+C-1
	cur=0;
	fact=1;
	j=i*C;
	while((j<(i+1)*C)and(j<K)):
		cur=cur+j*fact;
		j=j+1;
		fact=fact*K;
	while(j<(i+1)*C):
		cur=cur+(K-1)*fact;
		j=j+1;
		fact=fact*K;
	return cur+1;
		




for i in range(T):
	[K,C,S]=map(lambda x:int(x),raw_input().split());
	#print(S);
	#print(int(math.ceil(float(K)/C)));

	if(S>=int(math.ceil(float(K)/C))):

		ret=[];
		for j in range(0,int(math.ceil(float(K)/C))):
			ret.append(getNextInt(C,K,j));
		
		#print(ret)
		ans[i]=ret;	

for i in range(T):
	if(len(ans[i])==0):
		print("Case #"+str(i+1)+": IMPOSSIBLE");
	else:
		print("Case #"+str(i+1)+":"),
		for j in ans[i]:
			print(j),
		print('');	
		

			



