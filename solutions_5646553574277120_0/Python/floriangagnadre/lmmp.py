import sys
from copy import deepcopy

def opti(C,D,V,denominations):
	# C,D,V = 1,3,6
	# denominations = [1,2,5]
	wallet = [[d,C] for d in denominations]
	wallet.sort(key=lambda x:-x[0])
	new_d = 0
	for v in range(1,V+1):
		if not(cestpossible(v,wallet)):
			wallet.append([v,C])
			wallet.sort(key=lambda x:-x[0])
			new_d += 1
	return new_d

def cestpossible(v,wallet):
	# print(v,wallet)
	# si v = 0 ok
	if v==0:
		# print("true")
		return True
	# si j'ai plus de pieces, c'est perdu
	if len(wallet)==0:
		# print("false")
		return False
	# sinon je prends la plus grande et je recommence
	if wallet[0][0]<=v and wallet[0][1]>0:
		new_wallet = deepcopy(wallet)
		new_wallet[0][1]-=1
		if cestpossible(v-new_wallet[0][0],new_wallet):
			# print("true")
			return True
		# si ca marche pas je prends un plus petite
	else:
		return cestpossible(v,wallet[1:])

def parse(filename):
	cases = []
	T = 0
	with open(filename,'r') as f:
		T = int(f.readline())
		for i in range(T):
			CDV = f.readline().split()
			C = int(CDV[0])
			D = int(CDV[1])
			V = int(CDV[2])
			denominations = [int(x) for x in f.readline().split()]
			cases.append((C,D,V,denominations))
	return T, cases

def get_result_as_string(i, new_d):
	return "Case #%i: %i\n"%(i+1,new_d)

if __name__ == "__main__":
	if len(sys.argv) > 1:
		T, cases = parse(sys.argv[1])
		with open('lolilol.txt','w') as f:
			for i in range(T):
				case = cases[i]
				new_d = opti(case[0],case[1],case[2],case[3])
				print(get_result_as_string(i,new_d)[:-1])
				f.write(get_result_as_string(i,new_d))