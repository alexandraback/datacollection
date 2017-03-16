from math import sqrt

def isprime(num):
	if num==1:
		return False
	if num%2==0:
		return 2
	for i in range(3,int(sqrt(num))+1,2):
		if num%i==0:
			return i
		if i>10000000:
			return True
	return True


def gencoin(l):
	if l==1:
		return '1'
	s='1'
	for i in range(0,l-2):
		s+='0'
	s+='1'
	return s

t=int(input(''))
n=input('')
j=int(n[n.index(' ')+1:])
n=int(n[:n.index(' ')])
s=gencoin(n)
count=0
coins={}
rem=0
print('Case #{}:'.format(str(1)))
while count<j:
	#print(s)
	val=int(s,2)
	coins={}
	valid=True
	for i in range(2,11):
		val=int(s,i)
		#print('val ',val)
		k=isprime(val)
		#print('val ',val,' k ',k)
		if k==True:
			valid=False
			break
		if k!=True:
			coins[i]=k
	rem=s
	s=bin(int(s,2)+2)[2:]
	if valid:
		print(rem,coins[2],coins[3],coins[4],coins[5],coins[6],coins[7],coins[8],coins[9],coins[10])
		count+=1
