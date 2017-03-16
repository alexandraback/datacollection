import math;
def incBinStr(s):
	t=list(s);
	i=1;
	while((i<len(s)) and (t[i]=='1')):
		t[i]='0';
		i=i+1;
	if(i==len(s)):
		t.append('1');
	else:
		t[i]='1';
	return ''.join(t);

def str2base(s,base):
	cur=0;
	factor=1;
	for i in range(len(s)):
		cur=cur+int(s[i])*factor;
		factor=factor*base;
	return cur;	

def chkprime(N,toprint):
	if(N==2):
		return True;
	sq=int(math.floor(math.sqrt(N)));
	i=2;
	while(i<=sq and i<=10**5):

		if(N%i==0):
			if(toprint):
				print(i),
			return False;
		i=i+1;

	return True;

def solve(N,J):
	s='10000000000000000000000000000001';
	out=[];
	while(len(s)<=N):
		#print(s);
		flag=True;
		for i in range(2,11):
			num=str2base(s,i);
			if(chkprime(num,False)):
				flag=False;
				break;
		if(flag):
			# print('yes');
			out.append(s);
			if(len(out)==J):
				break;
		s=incBinStr(s);		
	return out;

o=solve(32,500);				
print("Case #1: ");
for i in o:
	print(i[::-1]),
	for j in range(2,11):
			num=str2base(i,j);
			chkprime(num,True);
	print('');		