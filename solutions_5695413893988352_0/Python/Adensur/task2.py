4
1? 2?
?2? ??3
? ?
?5 ?0

import os
import string
def Solve(dat):
	N1=len(dat[0])
	N2=len(dat[1])
	s=" ".join(dat)
	N="".join(s).count("?")
	result=[]
	for n in range(10**N):
		num="0"*(N-len(str(n)))+str(n)
		s2=s
		for ch in num:
			s2=string.replace(s2,"?",ch,maxreplace=1)
		C, J=s2.split(" ")
		C, J = int(C),int(J)
		result.append([abs(C-J),C,J])
	result.sort()
	C, J = result[0][1:]
	C="0"*(N1-len(str(C)))+str(C)
	J="0"*(N2-len(str(J)))+str(J)
	return C, J
data=[]
with open("B-small-attempt0.in") as handle:
	T=int(handle.readline().strip("\n"))
	for t in range(T):
		C, J = handle.readline().strip("\n").split(" ")
		data.append((C,J))
with open("output.txt","w") as handle:
	n=1
	for t in range(T):
		C,J=Solve(data[t])
		s="Case #%s: %s %s" % (n, C, J)
		print s
		handle.write(s+"\n")
		n+=1