import math

def func(r,c,f,x):
	t = 0
	lim = f*(x-c)/c
	# (c * r <= f * (x-c))
	while (r < lim):
		t += c/r
		r += f
	t += x/r
	return t

def takeInput():
	r = 2
	for case in range(int(input())):
		c,f,x = map(float,input().split())
		print("Case #{}: {:.7f}".format(case+1,func(r,c,f,x)))

takeInput()