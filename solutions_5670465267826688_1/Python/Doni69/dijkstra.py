lookup={"11": "1","1i": "i","1j": "j","1k": "k",
		"i1": "i","ii":"-1","ij": "k","ik":"-j",
		"j1": "j","ji":"-k","jj":"-1","jk": "i",
		"k1": "k","ki": "j","kj":"-i","kk":"-1", "--":""}

f=open("C-large.in")
w=open("C-large.out","w")
T=int(f.readline())
for test in range(T):
	L,X=f.readline().split()
	X=int(X)
	s=f.readline().strip()*(X%4+4 if X>4 else X)
	if len(s)<3:
		w.write("Case #{}: NO\n".format(test+1))
		continue
	elif len(s)==3:
		w.write("Case #{}: {}\n".format(test+1,"YES" if s=="ijk" else "NO"))
		continue
	copy="1"
	loc=[0,0]
	for i in range(len(s)):
		copy+=s[i]
		while len(copy.strip("-"))>1:
			if copy[0:2] in lookup:
				copy=lookup[copy[0:2]]+copy[2:]
			elif copy[1:3] in lookup:
				copy=copy[0]+lookup[copy[1:3]]+copy[3:]
		if copy[:2]=="--":copy=copy[2:]
		if not loc[0] and copy[0]=="i":
			loc[0]=i+1
			copy="1"
		elif loc[0] and not loc[1] and copy[0]=="j":
			loc[1]=i+1
			copy="1"
	w.write("Case #{}: {}\n".format(test+1,"YES" if loc[0] and loc[1] and copy=="k" else "NO"))

w.close()
