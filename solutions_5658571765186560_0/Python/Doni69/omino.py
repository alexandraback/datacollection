f=open("D-small-attempt2.in")
w=open("D-small-attempt2.out","w")
T=int(f.readline())
for test in range(T):
	X,R,C=[int(i) for i in f.readline().split()]
	if R*C%X or (X+1)//2>min(R,C) or X>max(R,C) or (X>3 and 2 in (R,C)):
		w.write("Case #{}: RICHARD\n".format(test+1))
	else:
		w.write("Case #{}: GABRIEL\n".format(test+1))

w.close()
