import math
import sys

Cmax = 20
res = [[0 for c in range(Cmax+1)] for w in range(Cmax+1)]
for w in range(1,Cmax+1):
	for c in range(w,Cmax+1):
		if w==c:
			res[w][c]=w
		elif c<2*w:
			res[w][c]=w+1
		else:# 2*w<=c donc c-w>=w
			res[w][c]=max(w+1,res[w][c-w]+1)

# for w in range(Cmax+1):
# 	print(' '.join([str(x) for x in res[w]]))

def opti(R,C,W):
	return (R-1)*math.ceil(float(C)/W)+res[W][C]

def parse(filename):
	cases = []
	T = 0
	with open(filename,'r') as f:
		T = int(f.readline())
		for i in range(T):
			RCW = f.readline().split()
			R = int(RCW[0])
			C = int(RCW[1])
			W = int(RCW[2])
			cases.append((R,C,W))
	return T, cases

def get_result_as_string(i, opt):
	return "Case #%i: %i\n"%(i+1,opt)

if __name__ == "__main__":
	# (T, cases) = parse("brattleship.txt")
	# for case in cases:
	# 	print(opti(case[0],case[1],case[2

	if len(sys.argv) > 1:
		T, cases = parse(sys.argv[1])
		with open('lolilol.txt','w') as f:
			for i in range(T):
				case = cases[i]
				opt = opti(case[0],case[1],case[2])
				print(get_result_as_string(i,opt)[:-1])
				f.write(get_result_as_string(i,opt))