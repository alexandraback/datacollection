def multiply(a,b):
	
	result = a
	signa = False
	signb = False
	sign = False
	if len(a) > 1:
		signa = a[0]
		a = a[1]
		sign = True
	if len(b) > 1:
		signb = b[0]
		b = b[1]
		sign = True

	if a == "1":
		result = b
	elif b == "1":
		result = a

	elif a == b:
		result = "-1"
	elif a == "-1":
		result = "-" + b
	elif b == "-1":
		result = "-" + a
	
	elif a == "i" and b == "j":
		result = "k"
	elif a == "i" and b == "k":
		result = "-j"
	elif a == "j" and b == "i":
		result = "-k"
	elif a == "j" and b == "k":
		result = "i"
	elif a == "k" and b == "i":
		result = "j"
	elif a == "k" and b == "j":
		result = "-i"

	if bool(signa) != bool(signb):
		if "-" in result:
			result = result[1]
		else:
			result = "-" + result
	
	return result

def solveDijkstraLarge():

	input = open("C-large.in", "r")
	output = open("C-large-output-Dijkstra", "w")

	test_cases = int(input.readline().strip("\n"))
	tc = 1

	for i in range(test_cases):
		L, X = map(int, input.readline().strip("\n").split(" "))
		single = input.readline().strip("\n")
		val = "1"
		for c in single * (X % 4):
		    val = multiply(val, c)

		result = val == "-1"

		if result:

		    S = single * (X % 4 + (4 if X >= 4 else 0))

		    p1 = p2 = -1

		    n1 = "1"
		    for i in range(len(S)):
				n1 = multiply(n1, S[i])
				if n1 == 'i':
				    p1 = i
				    break

		    n2 = "1"
		    for i in range(len(S)-1, -1, -1):
				n2 = multiply(S[i], n2)
				if n2 == 'k':
				    p2 = i
				    break

		    result = (p1 > -1 and p2 > -1) and p1 < p2 + (X * L - len(S))

		output.write('Case #{0}: {1}\n'.format(tc, ('YES' if result else 'NO')))
		tc += 1
	output.close()
	input.close()
							
				
	

	
