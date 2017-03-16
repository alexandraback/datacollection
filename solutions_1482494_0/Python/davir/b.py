def swp(a,b):
	c=a; a=b; b=c;

def min0(a):
	if a[2] == 0:
		return a[0]
	else:
		return 9999999999999

def min1(a):
	return a[1]

tc = int(raw_input())
for ct in range(1,tc+1):
	ans = 0

	n = int(raw_input())
	L = []
	for i in range(n):
		k = raw_input().split()
		L.append([int(k[0]),int(k[1]),0])
	s = 0
	c1 = 0
	while len(L) > 0:
		l1 = min(L,key=min0)
		l2 = min(L,key=min1)	
		if l2[1] <= s:		
			s += 1
			if l2[2] == 0:
				s+=1
			ans+=1
			L.remove(l2)
		elif (l1[0] <= s) and c1 <= n:
			c1+=1
			L.remove(l1)
			s+=1
			l1[2]=1
			L.append(l1)
			ans+=1
		else:
			ans = "Too Bad"
			break

	print "Case #" + str(ct) + ": " + str(ans)
