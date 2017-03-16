import math
import re

def solve(l):
	s = max(l)
	for a in range(1,s):
		s=min(s,reduce(lambda x,y:x-(-y)/a-1,l,a))
	return(s)

inp = open("B-small-attempt0.in","r")
out = open("B-small","w")
lines = inp.readlines()
for i in range(1,len(lines)/2+1):
	l = [int(x) for x in re.split(" ",lines[2*i])]
	out.write("Case #"+str(i)+": "+str(solve(l))+"\n")
out.close()
inp.close()
