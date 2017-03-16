import os

def DataFromFile(fname):
	with open(fname,"r") as f:
		tline=f.read()
	return tline
#
def TxtAppend(fname,s):
	with open(fname, "a") as f:
		f.write(s+"\n")
#
lnum=0
def NextLine():
	global lnum
	lnum=lnum+1
	return lines[lnum-1]
#
def ispower2(n):
	while (n>0) and (n%2==0):
		n=n/2
	#
	return n==1
#


from fractions import gcd

fdata=DataFromFile("elf.in")
fname="elf.out"
with open(fname, "w") as f:
	pass
#
lines=fdata.split("\n")
lines.pop()
cases=int(NextLine())
for k1 in xrange(cases):
	tmp=map(int, (NextLine()).split("/"))
	vP=tmp[0]  #Numerator
	vQ=tmp[1]  #Denominator
	#vP/vQ = "elf-ness" - how many generations ago had 1/1 somewhere.
	vGCD=gcd(vP,vQ)
	vP=vP/vGCD
	vQ=vQ/vGCD
	vP2=vP
	if ispower2(vQ):
		iter=0
		while 1:
			iter=iter+1
			vP2=vP2*2-vQ
			if (vP2>=0) and (vP2<=vQ):
				break  #found it.
			#
			if (vP2>vQ):
				vP2=vP2-vQ
			#
			if (vP2<0):
				vP2=vP2+vQ
			#
		#
	else:
		iter="impossible"
	#
	tmps="Case #"+str(k1+1)+": "+str(iter)
	#print tmps
	TxtAppend(fname,tmps)
# end of each case
