test = input()
i = 1
ans = "Case #"
st = ""
while i<=test:
	st = ""
	x,y = map(int,raw_input().split())
	if x > 0:
		st+="WE"*x
	elif x < 0:
		st+="EW"*(x*-1)
	if y > 0:
		st+="SN"*y
	elif y < 0:
		st+="NS"*(y*-1)
	print ans+str(i)+": "+st
	i+=1
	
