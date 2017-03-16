from sys import*

f=open("A-large.in","r+")
g=open("output.txt","w+")

T=int(f.readline())
for i in range(T):
	S=f.readline().strip()
	h={}
	for a in S:
		h.setdefault(a,0)
		h[a]+=1
	
	number=[]
	
	if "Z" in h:
		while h["Z"]>0:
			number.append(0)
			h["Z"]-=1
			h["E"]-=1
			h["R"]-=1
			h["O"]-=1
	
	if "W" in h:
		while h["W"]>0:
			number.append(2)
			h["T"]-=1
			h["W"]-=1
			h["O"]-=1
	
	if "U" in h:
		while h["U"]>0:
			number.append(4)
			h["F"]-=1
			h["O"]-=1
			h["U"]-=1
			h["R"]-=1
	
	if "X" in h:
		while h["X"]>0:
			number.append(6)
			h["S"]-=1
			h["I"]-=1
			h["X"]-=1
	
	if "O" in h:
		while h["O"]>0:
			number.append(1)
			h["O"]-=1
			h["N"]-=1
			h["E"]-=1
	
	if "R" in h:
		while h["R"]>0:
			number.append(3)
			h["T"]-=1
			h["H"]-=1
			h["R"]-=1
			h["E"]-=2
	
	if "S" in h:
		while h["S"]>0:
			number.append(7)
			h["S"]-=1
			h["E"]-=2
			h["V"]-=1
			h["N"]-=1
	
	if "V" in h:
		while h["V"]>0:
			number.append(5)
			h["F"]-=1
			h["I"]-=1
			h["V"]-=1
			h["E"]-=1
	
	if "G" in h:
		while h["G"]>0:
			number.append(8)
			h["E"]-=1
			h["I"]-=1
			h["G"]-=1
			h["H"]-=1
			h["T"]-=1
	
	if "N" in h:
		while h["N"]>0:
			number.append(9)
			h["N"]-=1
			h["I"]-=1
			h["N"]-=1
			h["E"]-=1
	
	number.sort()
	
	g.write("Case #{}: ".format(i+1))
	for ab in number:
		g.write(str(ab))
	g.write("\n")

f.close()
g.close()
