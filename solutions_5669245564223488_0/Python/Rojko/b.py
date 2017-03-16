def normal(s):
	t = s[0]
	for i in range(1,len(s)):
		if s[i] != s[i-1]:
			t+=s[i]
	return t 

def fac(x):
	f = 1
	for i in range(2,x+1):
		f*=i
	return f

def eq():
	global a

	if a[0][0] == a[0][-1] and len(a[0]) > 1: return False
	for i in range(1,len(a)):
		if a[i][0] == a[i][-1] and len(a[i]) > 1: return False
		if len(a[i]) == 1 or len(a[i-1]) == 1: continue
		if a[i][0] == a[i-1][0]: return False
	return True

def eqq():
	global a
	b = [x[::-1] for x in a]
	b.sort()

	for i in range(1,len(b)):
		if len(b[i]) == 1 or len(b[i-1]) == 1: continue
		if b[i][0] == b[i-1][0]: return False
	return True

def group0():
	global a
	c = []
	suc = 1
	poc = 1
	p = 0
	for i in range(1,len(a)):
		if a[i] == a[i-1]:
			poc+=1
		else:
			suc*=fac(poc)
			if poc > 1: 
				p += 1
			poc = 1
	suc*=fac(poc)
	if poc > 1: 
		p += 1
	a = list(set(a))
	return suc,p

def group1():
	global a
	i,j = 0,0
	a.sort()
	zmena = True
	while zmena:
		zmena = False
		c = []
		b = ["" for i in range(26)]
		for x in a:
			b[ord(x[0])-ord('a')] = x
		for x in a:
			tu = ord(x[0])-ord('a')
			if b[tu] == "": continue
			kde = ord(x[-1])-ord('a')
			if b[kde] == x: continue
			if b[kde] != "":
				c.append(x+b[kde])
				b[kde] = ""
				b[tu] = ""
				zmena = True
		for x in b:
			if x != "" : c.append(x)
		a = c
def group2():
	global a
	a = list(map(normal,a))
	b = [0 for i in range(26)]
	for x in a:
		b[ord(x[0])-ord('a')] = 1
	for x in a:
		for i in range(1,len(x)-1):
			c = x[i]
			if b[ord(c)-ord('a')] > 0: return False
			b[ord(c)-ord('a')]+=1;
	return True

T = int(input())
for t in range(T):
	n = int(input())
	a = list(map(normal,input().split()))
	a.sort()
	if not (eq() and eqq()):
		print("Case #",t+1,": 0",sep="")
	else:
		suc,p = group0()
		group1()
		if not group2():
			print("Case #",t+1,": 0",sep="")
		else:
			print("Case #",t+1,": ",fac(len(a))*suc,sep="")
