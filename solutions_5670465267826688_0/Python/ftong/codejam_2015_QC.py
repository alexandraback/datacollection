def mul(n1, n2):
	if n1[0] == "-":
		neg = mul(n1[1], n2)
		if neg[0] == "-":
			return neg[1]
		else:
			return "-" + neg
	elif n2[0] == "-":
		neg = mul(n1, n2[1])
		if neg[0] == "-":
			return neg[1]
		else:
			return "-" + neg	
	elif n1 == "1":
		return n2
	elif n2 == "1":
		return n1
	elif n1 == "i":
		if n2 == "i":
			return "-1"
		elif n2 == "j":
			return "k"
		else:
			return "-j"
	elif n1 == "j":
		if n2 == "i":
			return "-k"
		elif n2 == "j":
			return "-1"
		else:
			return "i"
	elif n1 == "k":
		if n2 == "i":
			return "j"
		elif n2 == "j":
			return "-i"
		elif n2 == "k":
			return "-1"
	else:
		print "error"
		return 0

def createDatabase(arr):
	n = len(arr)
	dat = [["0" for i in range(n + 1)] for j in range(n + 1)]
	for i in range(n + 1):
		dat[i][i] = "1"
	for diff in range(1, n + 1):
		for i in range(n - diff + 1):
			dat[i][i + diff] = mul(dat[i][i + diff - 1], arr[i + diff - 1])
	return dat

# def dijkstra(arr):
# 	n = len(arr)
# 	if n < 3:
# 		return False
# 	dat = createDatabase(arr)
# 	for i in range(1, n - 1):
# 		if dat[0][i] == "i":
# 			for j in range(i, n):
# 				if dat[i][j] == "j" and dat[j][n] == "k":
# 					return True
# 	return False

def iIndices(arr):
	valueIndices = []
	curr = "1"
	for i in range(len(arr)):
		curr = mul(curr, arr[i])
		if curr == "i":
			valueIndices.append(i)
	return valueIndices

def kIndices(arr):
	valueIndices = []
	curr = "1"
	for i in range(len(arr)):
		curr = mul(arr[len(arr) - 1 - i], curr)
		if curr == "k":
			valueIndices.append(len(arr) - 1 - i)
	return valueIndices

def getProduct(arr):
	curr = "1"
	for i in range(len(arr)):
		curr = mul(curr, arr[i])
	return curr

def dijkstra(arr):
	n = len(arr)
	if n < 3:
		return False
	elif getProduct(arr) != "-1":
		return False
	else:
		i_s = iIndices(arr)
		k_s = kIndices(arr)
		if len(i_s) > 0 and len(k_s) > 0:
			return min(i_s) < max(k_s)
		else:
			return False

fin = open("C-small-attempt1.in", 'r')
fout = open("out.txt", 'w')

cases = int(fin.readline())
for case in range(cases):
	L, X = str.split(fin.readline())
	letters = fin.readline()[:-1]
	arr = ""
	for i in range(int(X)):
		arr += letters
	if dijkstra(arr):
		ans = "YES"
	else:
		ans = "NO"
	fout.write("Case #" + str(case + 1) + ": " + ans + "\n")

fin.close()
fout.close()