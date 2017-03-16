from math import sqrt,floor
from decimal import Decimal as D
from decimal import getcontext
getcontext().prec=10000
T=input().split("\n")
file_out=open("/Volumes/MyPassport/GoogleDrive/ProgramDesign/GoogleCodeJam/2013/Round1/Bullseye.out","w")
for c in range(int(T[0])):
	r,t=T[c+1].split(" ")
	r,t=int(r),int(t)
	temp=D(4*r*r-4*r+1+8*t)
	R=D(1-2*r+temp.sqrt())/4
	file_out.write("Case #"+str(c+1)+": "+str(floor(R))+"\n")
file_out.close()