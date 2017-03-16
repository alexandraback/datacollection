import sys

def red(s):
	b1 = "+" in s
	b2 = "-" in s
	if (not b1) or (not b2): 
		if b1: return "+"
		if b2: return "-"
		return ""
	if s[0]=="+":
		i=0
		while s[i]=="+": i+=1
		return "+" + red(s[i:])
	if s[0]=="-":
		i=0
		while s[i]=="-": i+=1
		return "-" + red(s[i:])
	raise Exception("")

def rb(s):
	if len(s)==0: return s
	i=len(s)-1
	while s[i]=="+" and i>0: i-=1
	if s[i]=="+": i-=1
	return s[:i+1]

def flip(s):
	s=s[::-1]
	s=map(lambda x: "+" if x=="-" else "-", s)
	return "".join(s)	

def solve(s):
	print "-----"
	print s
	s=red(s)
	s=rb(s)
	print s
	print "------"
	if s=="": return 0
	if s[0]=="+":
		return 1 + solve("-" + s[1:])
	return 1 + solve(flip(s)) 	
		
file = sys.argv[1]
f = open(file, "r")
F = open("output.txt", "w")
f.readline()
L = f.readlines()
for i in range(len(L)):
	F.write("Case #"+str(i+1)+": "+str(solve(L[i].rstrip()))+"\n")
F.close()




