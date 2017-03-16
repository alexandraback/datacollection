MAX = 100

def P(n,m):
	# base case of recursion: zero is the sum of the empty list
	if m==0:
		yield []
		return
		
	if m == 1:
		yield [n]
		return
	
	# modify partitions of n-1 to form partitions of n
	for i in range(n+1):
		for p in P(n-i,m-1):
			p.append(i)
			yield p
		
nosurp = [[] for i in range(0,31)]
surp = [[] for i in range(0,31)]

def fx(parts,p):
	try:
		if max(map(max,parts)) >= p:
			return 1
	except ValueError:
		pass
	return 0

for i in range(0,31):
	for parts in P(i,3):
		if abs(parts[0]-parts[1])>2 or abs(parts[1]-parts[2])>2 or abs(parts[2]-parts[0])>2:
			continue
		elif abs(parts[0]-parts[1])==2 or abs(parts[1]-parts[2])==2 or abs(parts[2]-parts[0])==2:
			surp[i].append(parts)
		else:
			nosurp[i].append(parts)


t = int(raw_input())
scores = [0 for i in range(MAX)]
ans = [[0 for i in range(MAX+1)] for j in range(MAX+1)]

for T in range(t):
	s = map(int, str(raw_input()).split(' '))
	n = s[0]
	sn = s[1]
	p = s[2]
	scores[1:n+1] = s[3:]
	
	for i in range(1,n+1):
		for j in range(sn+1):
			if j==0:
				#print("Checking in : " + str(nosurp[scores[i]]))
				ans[i][j] = fx(nosurp[scores[i]],p) + ans[i-1][j]
			else:
				#print("Checking in : " + str(surp[scores[i]]))
				ans[i][j] = max(fx(surp[scores[i]],p) + ans[i-1][j-1], fx(nosurp[scores[i]],p) + ans[i-1][j])
		
		'''for k in range(n+1):
			for x in range(sn+1):
				print ans[i][x],
			print "\n"
		'''
	print("Case #" + str(T+1) + ": " + str(ans[n][sn]))
	
	
#print surp
