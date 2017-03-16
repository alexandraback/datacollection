T=int(raw_input())

for t in range(1,T+1):
	NJs = map(float, (raw_input().split()))
	N = NJs[0]
	Js = NJs[1:]
	OrigX = sum(Js)
	flag = 0
	Temp = Js
	Ntemp = N
	X = sum(Temp)
	while flag != 1:
		Temp = filter(lambda J: J<=(OrigX+X)/Ntemp,Temp)
		if len(Temp) == Ntemp:
			flag = 1
		Ntemp = len(Temp)
		X = sum(Temp)
		
#	SortedJs = sorted(Js)
#	Jmin = SortedJs[0]
#	Jsndmin = SortedJs[1]
	print 'Case #' + str(t) + ':',
	for J in Js:
#		ans = str(max(0.0, ((((2*X)/N)-J)/X)*100 ))
		if X == 0:
			if J==0.0:
				ans = str((100.0/Ntemp))
			else:
				ans = str(0.0)
		else:
			ans = str(max(0.0, ((((OrigX+X)/Ntemp)-J)/OrigX)*100 ))
#		if J!=Jmin:
#			ans = str(((Jmin+X-J)*100)/(2*X))
#		else:
#			ans = str(((Jsndmin+X-J)*100)/(2*X))
#	Ans = map(lambda J: if J!=Jmin: return (Jmin+X-J)/2*X) else: return (Jsndmin+X-J)/2*X, Js)
#	for ans in Ans:
		ans = ans.split('.')
		inte = ans[0]
		try:
			floate = ans[1]
		except:
			floate = ""
		floate += '0'*(6-len(floate))
		try:
			if floate[6]>='5':
				floate = floate[:5]+str(int(floate[5])+1)
			else:
				floate = floate[:6]
		except:
			floate = floate[:6]
		print inte+'.'+floate,
	print

