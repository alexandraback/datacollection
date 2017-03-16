

def case():
	e, r, n = map(int, input().split())
	
	v = list(map(int, input().split()))
	
	next_larger = [-1] * n
	
	stack = [n-1]
	
	for i in range(n-2,-1,-1):
		
		while len(stack) > 0 and v[stack[-1]] <= v[i]:
			stack.pop()
		
		if len(stack) > 0:
			next_larger[i] = stack[-1]
			
		stack.append(i)
			
	#print (next_larger)
	
	score = 0
	
	limit = e
	
	for i in range(n):
		
		#print(i,e)
		if next_larger[i] == -1:
			score += e*v[i]
			e = r
		else:
			target = max(0, limit - (next_larger[i]-i)*r)
			
			spend = 0
			if e > target:
				spend = e - target
				
			#print( e, target, spend)
			
			score += spend*v[i]
			e -= spend
			e += r
			
	
	return score
	
	
for t in range(1,int(input())+1):
	print ("Case #%d: %d" % (t, case()))