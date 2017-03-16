f=open("D-large.in")
w=open("D-large.out","w")
T=int(f.readline())
for test in range(T):
	X,R,C=[int(i) for i in f.readline().split()]
	if R*C%X or (X+1)//2>min(R,C) or X>max(R,C) or (X in (4,5) and 2 in (R,C)) or (X==6 and min(R,C)<4) or X>6:
		w.write("Case #{}: RICHARD\n".format(test+1))
	else:
		w.write("Case #{}: GABRIEL\n".format(test+1))

w.close()
