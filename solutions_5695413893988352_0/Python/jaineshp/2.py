t=input()
tid=1
c2=range(0,100)
c2=map(str,c2)
for i in range(10):
	c2[i]="0"+c2[i]
c3=range(0,1000)
c3=map(str,c3)
for i in range(10):
	c3[i]="00"+c3[i]
for i in range(10,100):
	c3[i]="0"+c3[i]
while t:
	t-=1
	s=raw_input().split()
	xc=s[0]
	xj=s[1]
	ans_c=0
	ans_j=0
	if len(xc)==1:
		if xc=="?" and xj=="?":
			ans_c=0
			ans_j=0
		elif xc=="?":
			ans_c=int(xj)
			ans_j=int(xj)
		elif xj=="?":
			ans_j=int(xc)
			ans_c=int(xc)
		print "Case #"+str(tid)+":",ans_c,ans_j
	elif len(xc)==2:
		fc=[]
		fj=[]
		fixed_c=[]
		fixed_j=[]
		for i in range(2):
			if xc[i]!="?":
				fixed_c.append(i)
			if xj[i]!="?":
				fixed_j.append(i)
		for i in range(len(c2)):
			# c check
			x=c2[i]
			ok=1
			for j in range(len(fixed_c)):
				if x[fixed_c[j]]!=xc[fixed_c[j]]:
					ok=0
					break
			if ok:
				fc.append(x)
			ok=1
			for j in range(len(fixed_j)):
				if x[fixed_j[j]]!=xj[fixed_j[j]]:
					ok=0
					break
			if ok:
				fj.append(x)
		mini=10**9
		finalc=[]
		finalj=[]
		for x in fc:
			for y in fj:
				if abs(int(x)-int(y))<mini:
					mini=abs(int(x)-int(y))
		stop=0
		for x in fc:
			for y in fj:
				if abs(int(x)-int(y))==mini:
					print "Case #"+str(tid)+":", x,y
					stop=1
					break
			if stop:
				break
	elif len(xc)==3:
		fc=[]
		fj=[]
		fixed_c=[]
		fixed_j=[]
		for i in range(3):
			if xc[i]!="?":
				fixed_c.append(i)
			if xj[i]!="?":
				fixed_j.append(i)
		for i in range(len(c3)):
			# c check
			x=c3[i]
			ok=1
			for j in range(len(fixed_c)):
				if x[fixed_c[j]]!=xc[fixed_c[j]]:
					ok=0
					break
			if ok:
				fc.append(x)
			ok=1
			for j in range(len(fixed_j)):
				if x[fixed_j[j]]!=xj[fixed_j[j]]:
					ok=0
					break
			if ok:
				fj.append(x)
		mini=10**9
		finalc=[]
		finalj=[]
		for x in fc:
			for y in fj:
				if abs(int(x)-int(y))<mini:
					mini=abs(int(x)-int(y))
		stop=0
		for x in fc:
			for y in fj:
				if abs(int(x)-int(y))==mini:
					print "Case #"+str(tid)+":", x,y
					stop=1
					break
			if stop:
				break

	tid+=1
