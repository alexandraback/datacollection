f = open("B-small-attempt0.in", "r")
new_file = open("csmallSol", "w")
t = int(f.readline())


def possible_combinations (j,p,s,k):
	all_combinations = []
	if k >= s:
		n = j*p*s
		for a in range(1,j+1):
			for b in range(1,p+1):
				for c in range(1,s+1):
					this_combination = [str(a),str(b),str(c)]
					all_combinations.append(this_combination)
		return (n,all_combinations)
	else:
		if k == 1:
			n = j*p
			for a in range(1,j+1):
				for b in range(1,p+1):
					this_combination = [str(a), str(b), str((b+(a-1))%s + 1)]
					all_combinations.append(this_combination)
			return (n,all_combinations)
		else:
			n = j*p*2
			for a in range(1,j+1):
				for b in range(1,p+1):
					for c in [1,2]:
						this_combination = [str(a), str(b), str((b+(a-1)+c-1)%s + 1)]
						all_combinations.append(this_combination)
			return (n,all_combinations)
for i in range(1,t+1):
	j,p,s,k = [int(x) for x in f.readline().split(" ")]
	n, combinations = possible_combinations(j,p,s,k)
	new_file.write("Case #"+str(i)+ ": "+str(n)+"\n")
	for i in range(n):
		new_file.write(" ".join(combinations[i])+"\n")