def mul(a,b):
	minus=0
	if a[0]=='-':
		minus+=1
		x=a[1]
	else:
		x=a[0]
	if b[0]=='-':
		minus+=1
		y=b[1]
	else:
		y=b[0]
	if x=='1':
		if minus%2==1:
			y='-'+y
		return y
	if y=='1':
		if minus%2==1:
			x='-'+x
		return x
	if x==y:
		if minus%2==1:
			return '1'
		return '-1'
	use='ijkij'
	for i in range(0,3):
		if x==use[i] and y==use[i+1]:
			if minus%2==1:
				return '-'+use[i+2]
			return use[i+2]
		if x==use[i+1] and y==use[i]:
			if minus%2==0:
				return '-'+use[i+2]
			return use[i+2]
'''
while 1:
	a = input()
	b = input()
	print('r',mul(a,b))
'''
NumberOfTestCases = int( input() )
for NumTestCases in range(1,NumberOfTestCases+1):
	print('Case #',NumTestCases,': ',sep='',end='')
	L,X=map(int,input().split())
	ori=input()
	sum='1'
	for x in ori:
		sum = mul(sum,x)
	tmp=ori*4
	end=len(tmp)
	Iuse=0
	r='1'
	while Iuse<end:
		r=mul(r,tmp[Iuse])
		if r=='i':
			break
		Iuse+=1
	Kuse=end-1
	r='1'
	while Kuse>=0:
		r=mul(tmp[Kuse],r)
		if r=='k':
			break
		Kuse-=1
	#print(Iuse,Kuse)
	if Iuse>=end or Kuse<0:
		print('NO')
		continue
	Ilen=Iuse+1
	Klen=end-Kuse
	#print(Ilen,Klen)
	if Ilen+Klen>=L*X:
		print('NO')
		continue
	result = '1'
	if Ilen%L>0:
		for i in range(Ilen%L,L):
			result=mul(result,ori[i])
	#tmp=ori[Ilen%L:L]
	mid = L*X - ((Ilen-1)//L+1)*L - ((Klen-1)//L+1)*L
	mid = mid//L
	mid = mid%4
	for i in range(0,mid):
		result=mul(result,sum)
	for i in range(0,Kuse%L):
		result=mul(result,ori[i])
	if result=='j':
		print('YES')
	else:
		print('NO')
