import sys

f= open(sys.argv[1], "r")
F= open(sys.argv[1]+"output", "w")

N_SET = set(range(10))

def solve(s):
	if s.rstrip()=="0":
		return "INSOMNIA"
	return str(solveI(int(s.rstrip())))

def solveI(n):
	CURR_SET=set([])
	N=0
	while CURR_SET!=N_SET:
		N+=n
		CURR_SET=add(N, CURR_SET)
	return N

def add(N, CURR_SET):
	nums = map(lambda x: int(x), list(str(N)))
	return CURR_SET.union(nums)
	
f.readline()
lines = f.readlines()
for i in range(len(lines)):
	F.write("Case #"+str(i+1)+": "+solve(lines[i]) + "\n")



