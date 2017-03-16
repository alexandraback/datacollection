

def case():
	r, n, m, k = map(int, input().split())
	
	answers = []
	
	for i in range(r):
		products = list(map(int, input().split()))
		
		#print(products)
		
		possible = []
		
		for a in range(2,6):
			for b in range(2,6):
				for c in range(2,6):
					
					t = [1, a, b, c, a*b, a*c, b*c, a*b*c]
					if all(p in t for p in products):
						possible.append( [a,b,c] )
						
		answers.append("".join(map(str,possible[0])))
		
	return "\n".join(answers)
	
	
for t in range(1,int(input())+1):
	print ("Case #%d:\n%s" % (t, case()))