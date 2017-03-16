T = int(input())
for tc in range(1,T+1):
	[x,r,c]=[int(z) for z in input().split()]
	sol = True
	if x>6 or (x>r and x>c) or r*c%x > 0 or (x+1)>>1 > min(r,c):
		sol = False
	elif x in [1,2,3]:
		pass
	elif x==4 and min(r,c) <3:
		sol = False
	elif x==5:  
		sol = not(min(r,c) == 3 and max(r,c)==5)
	elif x == 6:
		sol = min(r,c) > 3
	
	if sol:
		print("Case #{_tc}:".format(_tc=tc),'GABRIEL')
	else:
		print("Case #{_tc}:".format(_tc=tc),'RICHARD')
