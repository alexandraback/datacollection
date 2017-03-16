ans = 0

def search (a,i,v):
	global ans
	for x in range(1,n+1):
		if (a[x]==i):
			if (x not in v):
				put_direct(a,x,v[:])
	if (len(v)>ans):
		ans = len(v)

def put_direct(a,i,v):
	global ans
	v.append(i)
	flag = 0
	while (a[i] not in v):
		if (a[a[i]] not in v):
			v.append(a[i])
			i = a[i]
		else:
			if (a[a[i]] == v[0]):
				v.append(a[i])
				i = a[i]
				flag = 1
				if (len(v)>ans):
					ans = len(v)
			elif (a[a[i]]==v[-1]):
				v.append(a[i])
				i = a[i]
				if (len(v)>ans):
					ans = len(v)
			break
	if (flag==0):
		search(a,i,v)


for t in xrange(int(raw_input())):
	global ans
	ans = 0
	n = int(raw_input())
	a = [0]+map(int, raw_input().split())
	for i in range(1,n+1):
		put_direct(a,i,[])
	print ans
