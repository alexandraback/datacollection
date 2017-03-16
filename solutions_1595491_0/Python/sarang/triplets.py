t = int(raw_input())
for c in range(1,t+1):
	l = [int(i) for i in raw_input().strip().split()]
	
	L = l[3:]
	N,S,p = l[0],l[1],l[2]

	res = 0
	for e in L:
		good = False 
		for q in range(p,11):
			if((3*q == e) or ((3*q-1 == e) and (q-1 >= 0)) or ((3*q-2 == e) and (q-1 >= 0))):
				good = True
				break
		if (not good) and (S > 0):
			for q in range(p,11):
				if(((3*q-3 == e) and (q-2 >= 0)) or ((3*q-4 == e) and (q-2 >= 0))):
					good = True
					S -= 1
					break
		if(good): res += 1;


	print "Case #%d: %d"%(c,res)
