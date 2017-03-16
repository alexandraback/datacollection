MAX_FACT_SEARCH = 10000

def isJamCoin(s):
	results=[]
	for i in range(2,11):
		n=int(s,i)
		for div in range(2,min(MAX_FACT_SEARCH,n/2)):
			if n%div==0:
				results.append(str(div))
				break
		if div==MAX_FACT_SEARCH-1:
			return ""
	return " ".join(results)

N=16
J=50
F=open("N:"+str(N)+",J:"+str(J),"w")
F.write("Case #1:\n")

def lP(N,L):
	s=bin(N)[2:]
	if len(s)>L: raise Exception("")
	return "0"*(L-len(s)) + s
i=0
while J>0:
	s=isJamCoin("1" + lP(i,N-2) + "1")
	if s!="":
		F.write("1" + lP(i,N-2) + "1" + " " + s + "\n")
		J-=1
	i+=1


