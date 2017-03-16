#!/usr/bin/env python

import sys

def A(N,S):
	if N==1:
		return [1.0]
	sumval=sum(S)
	x=float(2*sumval)/N
	sumval2=0
	count=0
	for i in range(0,N):
		if x>S[i]:
			sumval2+=S[i]
			count+=1
	ret=[(x-S[i])/sumval for i in range(0,N)]
	if count==N:
		return ret
	x2=float(sumval+sumval2)/count
	for i in range(0,N):
		if x>S[i]:
			ret[i]=(x2-S[i])/sumval
		else:
			ret[i]=0
	return ret



if __name__=="__main__":
	inpfile=open(sys.argv[1],'r')
	T=int(inpfile.readline())
	for i in range(0,T):
		l=[int(s) for s in inpfile.readline().split()]
		ret=A(l[0],l[1:])
		print('Case #'+str(i+1)+':',end=" ")
		for c in ret:
			print("%.5f"%(c*100),end=" ")
		print()
	inpfile.close()

