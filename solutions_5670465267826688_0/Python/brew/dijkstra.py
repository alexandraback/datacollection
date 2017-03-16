def solve(base_string,repetitions):
	if repetitions > 11: 
		repetitions = 11 + (repetitions - 11) % 4
	
	x = base_string * repetitions
	ans = x[0]
	prev = ans
	j = 0
	gotholdofi = False
	
	for letter in x[1:]:
		if ans == "i":
			x = x[j+1:]
			gotholdofi = True
			break
		j = j + 1
		ans = Dmult(prev.replace("-",""),letter)
		if prev[0] == "-" and ans[0] == "-":
			ans = ans[1]
		elif prev[0] == "-" and ans[0] != "-":
			ans = "-" + ans[0]
		prev = ans	

	if gotholdofi:
		# Found i from before, let's go hunt for j.
		gotholdofj = False
		ans = x[0]
		prev = ans
		j = 0
		for letter in x[1:]:
			if ans == "j":
				x = x[j+1:]
				gotholdofj = True
				break
			j = j + 1
			ans = Dmult(prev.replace("-",""),letter)
			if prev[0] == "-" and ans[0] == "-":
				ans = ans[1]
			elif prev[0] == "-" and ans[0] != "-":
				ans = "-" + ans[0]
			prev = ans

		if gotholdofj:
			# Got j, now k's turn...

			ans = x[0]
			prev = ans
			j = 0
			for letter in x[1:]:
				j = j + 1
				ans = Dmult(prev.replace("-",""),letter)
				if prev[0] == "-" and ans[0] == "-":
					ans = ans[1]
				elif prev[0] == "-" and ans[0] != "-":
					ans = "-" + ans[0]
				prev = ans
				
			if ans == "k":
				return "YES"
	
	return "NO"

def Dmult(a,b):
	if a == b and a != "1":
		return "-1"
	elif a == b and a == "1":
		return "1"
	elif a == "1":
		return b
	elif b == "1":
		return a
	elif a == "i" and b == "j":
		return "k"
	elif a == "i" and b == "k":
		return "-j"
	elif a == "j" and b == "i":
		return "-k"
	elif a == "j" and b == "k":
		return "i"
	elif a == "k" and b == "i":
		return "j"
	elif a == "k" and b == "j":
		return "-i"
	return 0


g = open("C-small-out.txt","w")


f = open("C-small.in","r")
d = f.read().split("\n")
n = int(d[0])

j = 1
for i in range(1,2*n+1,2):

	repetitions = int(d[i].split(" ")[1])
	base_string = d[i+1]

	g.write ("Case #" + str((i+1)/2) + ": " + solve(base_string,repetitions) + "\n")