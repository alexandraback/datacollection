from decimal import *
f=open('p.txt','r')
g=open('t.txt','w')

for i in range(1,1+int(f.readline())):
	[a,b]=[int(j) for j in f.readline().split()]
	v=[Decimal(j) for j in f.readline().split()]
	e3=Decimal(b)+2
	p=1
	for j in v:
		p*=j
	e1=Decimal(p)*(b-a+1)+(1-p)*(b-a+2+b)
	p=Decimal(1)
	e2=99999999
	for j in range(len(v)-1):
		p*=v[j]
		temp=Decimal(p)*(a-j+b-j-1)+(1-p)*(a-j+b-j+b)
		print p,temp
		if temp<e2: e2=temp
	win=e1
	if e2<e1: win=e2
	if e3<win: win=e3
	print 'Case #'+str(i)+': ' + str(win)
	g.write('Case #'+str(i)+': ' + str(win)+'\n')
g.close()
