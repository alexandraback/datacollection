import sys
import time
import math



with open(sys.argv[1]) as f:
	T  = int(f.readline())
	content = f.readlines()



def getn(name,n):
	pass

def fast(name,n):
	f = []
	for i in range(len(name)):
		if name[i] in "aeiou":
			f.append('v')
		else:
			f.append('k')
	ff = []
	cnt = 0
	starts = {}
	pos = [0] * (len(name)-n+1)
	buf = {}
	L = [0] * len(pos)
	cont = 0
	for i in range(len(name)-1,-1,-1):
		if not name[i] in "aeiou":
			cont = cont + 1
		else:
			cont = 0
		if cont >= n:
			L[i] = 1


	for i in range(len(name)-n+1):
		if L[i]:
			pos[i] = 1
			cnt = cnt + 1
			ff.append("*")
		else:
			ff.append(".")

	I = 0
	Ipos = [0] * len(pos)
	for i in range(len(pos)):
		if pos[i] == 1:
			I = I +1
		Ipos[i] = I
	cnt = 0
	#print Ipos
	for i in range(len(pos)):

		if pos[i]:
			#print "1For","i",i,":",len(pos)-i
			cnt = cnt + len(pos) - i;
			continue
		

		d = (float(len(pos)-1)-i)/2
		pp = i+d
		for j in range(int(math.log(len(pos),2)+30)):
			#print pp,d
			if Ipos[i] < Ipos[int(pp)]:
				pp = pp - d

			else:
				pp = pp + d
			pp = min(pp,len(pos)-1.)
			d = d / 2
		#print "fin",pp,d
		p = min(len(pos)-1,int(pp+0.01))
		if Ipos[i] < Ipos[p]:
			steps = len(pos)-i
			missed = p-i
			#print "p=",p,"i=",i,"n=",n,"len=",len(pos),"steps=",steps,"missed=",missed
			pot = len(pos)-i-n+1
			missed = p-i
			
			cnt = cnt + steps-missed
		else:
			#print "0 at i=",i,"p=",p,"i=",i,"n=",n,Ipos[i],Ipos[p]
			pass
			#print "3For","i",i,":",p,i,p-i+1

		"""
		for j in range(i,len(pos)):

			#binary search
			if Ipos[i] < Ipos[j] or pos[i]:
				cnt = cnt + len(pos) - i

				break
				#print i,j,name[i:j+3]
			else:
				pass
				#pass
				#print i,j,"NOPE",name[i:j+3],pos[i],pos[j]
		"""


	return cnt


for t in range(T):
	row = content[t].strip().split()
	name = row[0]
	#name = "nnnnnnnnnn"*100000
	n = row[1]
	f = fast(name,long(n))
	#print name,f
	print "Case #%d: %d" % (t+1,f)
	getn(name,n)