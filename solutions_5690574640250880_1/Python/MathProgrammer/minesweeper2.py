
def REK(col,maxi,C,O,part):
	if O<0:
		return(part,0)
	if col>C:
		return(part,0)
	if col==C:
		if O==0:
			return(part,1)
		return(part,0)
	if O==0:
		return(part,1)
	if col==0:
		for k in range(maxi,1,-1):
			part.append(k)
			ex=0
			if col==0:
				part.append(k)
				ex=1
			(part,done)=REK(col+1+ex,k,C,O-(1+ex)*k,part)
			if done==1:
				return(part,1)
			else:
				del(part[-1])
				if ex:
					del(part[-1])
	else:
		for k in range(maxi,1,-1):
			if k!=maxi-1:
				part.append(k)
				ex=0
				if col==0:
					part.append(k)
					ex=1
				(part,done)=REK(col+1+ex,k,C,O-(1+ex)*k,part)
				if done==1:
					return(part,1)
				else:
					del(part[-1])
					if ex:
						del(part[-1])
			else:
				if col>=2:
					part.append(k)
					(part,done)=REK(col+1,k,C,O-k,part)
					if done==1:
						return(part,1)
					else:
						del(part[-1])
	return (part,0)

f=open("C-large.in","r")
T=int(f.readline().strip())

answers=["" for i in range(T)]

for i in range(T):
	(R,C,M)=tuple([int(j) for j in list(f.readline().split())])
	O=R*C-M
	
	done=0
	
	if O==1:
		done=1
		for j in range(R):
			for k in range(C):
				if j==k and k==0:
					answers[i]+='c'
				else:
					answers[i]+='*'
			if j<R-1:
				answers[i]+='\n'
	
	if done==0 and O==R*C:
		done=1
		for j in range(R):
			for k in range(C):
				if j==k and k==0:
					answers[i]+='c'
				else:
					answers[i]+='.'
			if j<R-1:
				answers[i]+='\n'
	
	if done==0 and R==1:
		answers[i]="c"
		for j in range(O-1):
			answers[i]+="."
		for j in range(C-O):
			answers[i]+="*"
		done=1
	
	if done==0 and C==1:
		answers[i]="c\n"
		for j in range(O-1):
			answers[i]+="."
			if j<R-1:
				answers[i]+="\n"
		for j in range(R-O):
			answers[i]+="*"
			if j+O<R-1:
				answers[i]+="\n"
		done=1
		
	if not done:
		lis=[]
		party=REK(0,R,C,O,lis)[0]
		if len(party)==0:
			party=REK(0,C,R,O,lis)[0]
		
		if len(party)==0:
			answers[i]="Impossible"
		else:
			for j in range(R):
				for k in range(C):
					if j==k and k==0:
						answers[i]+='c'
					elif k<len(party):
						if j<party[k]:
							answers[i]+='.'
						else:
							answers[i]+='*'
					else:
						answers[i]+='*'
				if j<R-1:
					answers[i]+="\n"
	
f.close()

f=open("OUTPUT.txt","w")
for i in range(T):
	f.write("Case #{}:\n{}\n".format(i+1,answers[i]))
	#print("Case #{}:\n{}\n".format(i+1,answers[i]))
f.close()
