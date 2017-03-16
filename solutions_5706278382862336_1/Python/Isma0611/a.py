from fractions import Fraction
f=open('A-large.in','r')
t=int(f.readline())


def is_power2(num):
	return num != 0 and ((num & (num - 1)) == 0)

o=open('oal','w+')
ti=1
while ti<=t :
	p,q=(int(v)  for v in f.readline().split('/'))
	
	g=0
	x=Fraction(p,q)
	p=x.numerator
	q=x.denominator
	if not is_power2(q):
		s=str("impossible")
	else:
		while p < q:
			p*=2
			g+=1

		s=str(g)	
	# print s
	ss= str("Case #")+str(ti)+str(": ")+ s + str('\n')
	o.write(ss)
	# print ss


	ti+=1

