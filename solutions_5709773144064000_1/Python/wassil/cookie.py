def time(r,c,f,x):
	result = 0
	while True:
		if x/r <= c/r + x/(r+f):
			return result + x/r
		else:
			result += c/r
			r += f

for case in range(int(input())):
	result = 0.0
	C,F,X = map(float, input().split())
	#print("%f %f %f",C,F,X)
	print ("Case #%d: %.7f" %(case+1, time(2.0,C,F,X)))


