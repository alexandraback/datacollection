# prepare full ??????? ??????? for large


T = int(input()) # cases

def hasQ(r):
	for s in r:
		if(not isinstance(s,str)):
			continue
		for c in s:
			if(c=="?"):
				return True
	return False

def value(C):
	s = 0
	for c in C:
		s*=10
		s+=int(c)
	return s

def tostr(C):
	s = ""
	for c in C:
		s+=c
	if("?" in s):
		return s
	else:
		return int(s)
	# return s

def compare(c1,j1,c2,j2):
	C1 = 0
	for c in c1:
		C1*=10
		C1+=int(c)
	J1 = 0
	for c in j1:
		J1*=10
		J1+=int(c)
	C2 = 0
	for c in c2:
		C2*=10
		C2+=int(c)
	J2 = 0
	for c in j2:
		J2*=10
		J2+=int(c)
	
	print(C1,C2,J1,J2)
	
	if(abs(c1-j1)<abs(c2-j2)):
		return True
	if(abs(c1-j1)>abs(c2-j2)):
		return False
	if(c1<c2):
		return True
	if(c1>c2):
		return False
	if(j1<j2):
		return True
	
def diff(i,C,J):
	return abs(int(C[i])-int(J[i]))
	
def cint(a,C,r,b=3):
	s=0
	for i in range(b):
		s*=10
		if(C[a+i]=="?"):
			s+=r
		else:
			s+=int(C[a+i])
	return s

def findall(C):
	r = []
	Cv = 0
	for c in C:
		if(c=="?"):
			Cv+=1
	if(Cv==0):
		return [int("".join(C))]
	if(Cv>0):
		for i in range(len(C)):
			if(C[i]=="?"):
				Ci = C[:]
				Ci[i]="0"
				r.append(tostr(Ci))
				Ci[i]="1"
				r.append(tostr(Ci))
				Ci[i]="2"
				r.append(tostr(Ci))
				Ci[i]="3"
				r.append(tostr(Ci))
				Ci[i]="4"
				r.append(tostr(Ci))
				Ci[i]="5"
				r.append(tostr(Ci))
				Ci[i]="6"
				r.append(tostr(Ci))
				Ci[i]="7"
				r.append(tostr(Ci))
				Ci[i]="8"
				r.append(tostr(Ci))
				Ci[i]="9"
				r.append(tostr(Ci))
				Cv-=1
				break
				
	# print(r)
	# print()
	while(hasQ(r)):
		for s in r:
			if(not isinstance(s,str)):
				continue
			s = list(s)
			for i in range(len(s)):
				if(s[i]=="?"):
					Ci = s[:]
					Ci[i]="0"
					r.append(tostr(Ci))
					Ci[i]="1"
					r.append(tostr(Ci))
					Ci[i]="2"
					r.append(tostr(Ci))
					Ci[i]="3"
					r.append(tostr(Ci))
					Ci[i]="4"
					r.append(tostr(Ci))
					Ci[i]="5"
					r.append(tostr(Ci))
					Ci[i]="6"
					r.append(tostr(Ci))
					Ci[i]="7"
					r.append(tostr(Ci))
					Ci[i]="8"
					r.append(tostr(Ci))
					Ci[i]="9"
					r.append(tostr(Ci))
					Cv-=1
					r.remove("".join(s))
					break
	# print(r)
	return r

for Ti in range(T):
	tmp = input().split(" ")
	C = list(tmp[0])
	J = list(tmp[1])
	Cv = 0
	Jv = 0
	
	for c in C:
		if(c=="?"):
			Cv+=1
	for c in J:
		if(c=="?"):
			Jv+=1
	
	bC = C[:]
	bJ = J[:]
	for j in range(len(bC)):
		if(bC[j]=="?"):
			bC[j]="0"
	minC = value(bC)
	
	for j in range(len(bJ)):
		if(bJ[j]=="?"):
			bJ[j]="0"
	minJ = value(bJ)
	
	# for i in range(Cv):
	posC = sorted(findall(C))
	posJ = sorted(findall(J))
	# print(posC)
	# print(posJ)
	
	mindiff = 99999999999999999999999999
	cr = 0
	jr = 0
	for a in posC:
		for b in posJ:
			if(abs(a-b)<mindiff):
				cr=a
				jr=b
				mindiff=abs(a-b)
	
	# pad with 0 from original input
	print("Case #"+str(Ti+1)+":",str(cr).zfill(len(C)),str(jr).zfill(len(J)))
		
	
	# print(Cv,Jv)
	# print(minC,minJ)


