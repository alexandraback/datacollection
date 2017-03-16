r = []
for j in range(1, 2000001):
	x = str(j)
	for k in range(0,len(x)):
		x = x[-1] + x[0:-1]
		y = int(x)
		if j < y and y <= 2000001 and y >= 1:
			r.append((j,y))
l = list(set(r))
N = int(raw_input())
for i in range(1, N+1):
	s = raw_input()
	v = s.split()
	A = int(v[0])
	B = int(v[1])
	r = 0
	for (a, b) in l:
		if a>=A and b<=B:
			r += 1
	print("Case #{i}: {r}".format(i=i,r=r))

