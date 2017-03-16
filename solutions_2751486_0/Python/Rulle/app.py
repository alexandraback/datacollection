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
	for i in range(len(name)-n+1):
		if all(f[i] == 'k' for i in range(i,i+n)):
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
	for i in range(len(pos)):
		for j in range(i,len(pos)):
			if Ipos[i] < Ipos[j] or pos[i]:
				cnt = cnt + 1
				#print i,j,name[i:j+3]
			else:
				pass
				#pass
				#print i,j,"NOPE",name[i:j+3],pos[i],pos[j]



	return cnt


for t in range(T):
	row = content[t].strip().split()
	name = row[0]
	n = row[1]
	f = fast(name,int(n))
	#print name,f
	print "Case #%d: %d" % (t+1,f)
	getn(name,n)