from __future__ import print_function
g = open('inp.txt','r')
f = open('out.txt','w')
def _operate(k,c,s):
	if c == 1:
		if k!=s:
			return "IMPOSSIBLE"
		A=[]
		for i in range(1,k+1):
			A.append(i)
		return A
	A=[]
	if k==1:
		A.append(1)
		return A
	if k==2:
		A.append(2)
		return A
	A = [2]
	for i in range(3,k,2):
		A.append((i-1)*k+i+1)
	if k&1:
		A.append(pow(k,c))
	if len(A) > s:
		return "IMPOSSIBLE"
	return A			
t = int(g.readline())

for tt in range(1,t+1):
	k,c,s = map(int,g.readline().split())
	f.write("Case #"+str(tt)+": ")
	op = _operate(k,c,s)
	if op=="IMPOSSIBLE":
		f.write("IMPOSSIBLE\n")
		continue
	for i in range(0,len(op)):
		f.write(str(op[i])+" ")
	f.write("\n")
			
