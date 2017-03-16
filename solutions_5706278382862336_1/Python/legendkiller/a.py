def findgcd (x,y):
	temp = -1
	while temp!=1 and temp!= 0 :
		if x < y :
			y = y%x 
			temp = y
		else:
			x = x%y 
			temp = x
	
	if temp == 1:
		return 1
	else:
		return max(x,y)
		
def power(x):
	c = 0
	while x%2 != 1:
		c = c + 1
		x = x/2
	return (c,x)
#-------------------------------------

t = int(input());
for i in range(0,t):
	s = input()
	l = []
	l = s.split('/')
	p = int(l[0])
	q = int (l[1])
	x = findgcd(p,q)
	p = p/x
	q = q/x
	(res,g) = power(q)
	if (g != 1):
		print("Case #"+ str(i+1) +": "+"impossible")
	else:
		temp = 0;
		while p < q :
			q = q/2
			temp = temp +1
		print("Case #"+str(i+1)+": "+str(temp))
	
