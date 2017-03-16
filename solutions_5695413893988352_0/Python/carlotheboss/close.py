def Confronta(s, modello):
	for i in range(len(s)):
		if modello[i]!='?' and s[i] != modello[i]: return False
	
	return True
	
	
for i in range(int(input())):
	s=input().split(' ')
	S1,S2=s[0],s[1]
	l=len(S1)
	arrivo=10**l
	trov=-1
	s_c=""
	s_j=""
	v1,v2=[],[]
	s1,s2=[],[]
	for k in range(0, arrivo):
		d=str(k)
		while len(d) < l:
			d="0"+d
		if Confronta(d, S1): 
			v1.append(k)
			s1.append(d)
		if Confronta(d, S2): 
			v2.append(k)
			s2.append(d)

	for k in range(len(v1)):
		for k2 in range(len(v2)):
			if trov==-1 or abs(v1[k]-v2[k2]) < trov:
				trov=abs(v1[k]-v2[k2])
				s_c=s1[k]
				s_j=s2[k2]
	
	print("Case #%d: %s %s" %(i+1, s_c, s_j))
