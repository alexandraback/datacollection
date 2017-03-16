from __future__ import print_function
g = open('inp.txt','r')
f = open('out.txt','w')
t = int(g.readline())
for tt in range(1,t+1):
	k,c,s = map(int,g.readline().split())
	f.write("Case #"+str(tt)+": ")
	if(s == k):
		for i in range(1,k+1):
			f.write(str(i)+" ")
		f.write("\n")
	else:
		f.write("IMPOSSIBLE\n")
				