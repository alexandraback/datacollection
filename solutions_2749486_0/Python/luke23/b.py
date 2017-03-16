c=int(input())

def f(a,b):
	x=0
	y=0
	st=""
	s=1
	while x!=a:
		d=x-a
		if d>0:
			st+="E"
			x+=s
			s+=1
			st+="W"
			x-=s
			s+=1
		else:
			st+="W"
			x-=s
			s+=1
			st+="E"
			x+=s
			s+=1
	while y!=b:
		d=y-b
		if d>0:
			st+="N"
			y+=s
			s+=1
			st+="S"
			y-=s
			s+=1
		else:
			st+="S"
			y-=s
			s+=1
			st+="N"
			y+=s
			s+=1
	return st
for i in range(c):
	v=raw_input().split()
	v=[int(x) for x in v]
	n=f(v[0],v[1])
	print ("Case #"+str(i+1)+": "+n)

