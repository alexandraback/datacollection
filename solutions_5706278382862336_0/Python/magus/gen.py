t = input()
for case in range(1,t+1):
	p,q = [float(x) for x in raw_input().split("/")]
	ans = p/q
	count = -1
	pehla = -1
	while(count<40):
		#print ans
		count+=1
		if(ans>=1 and pehla ==-1):
			pehla = count
		if(ans>1):
			ans = ans-1
		if(ans==1):
			break
		ans *= 2
		
	if(ans==1):
		print("Case #{}: {}".format(case, pehla))
	else:
		print("Case #{}: {}".format(case, "impossible"))
	
