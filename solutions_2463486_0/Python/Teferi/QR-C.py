#Fair and Square
l=range(1,10)
for i in range(1,10000) :
	l.append(int(str(i)+str(i)[::-1]))
	for k in range(10) :
		l.append(int(str(i)+str(k)+str(i)[::-1]))
l.sort()
l=[str(x**2) for x in l]
l=map(int,filter(lambda x:x==x[::-1],l))

t=input()
for tt in range(t) :
	a,b=map(int,raw_input().split())
	n=len(filter(lambda x:a<=x<=b, l))
	print "Case #%d:"%(tt+1),n
