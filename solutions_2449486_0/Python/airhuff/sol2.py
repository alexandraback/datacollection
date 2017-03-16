arr = []

def row_check(vec,h):
	if vec.count(h) == len(vec):
		return True
	return False

def isposs(h):
	global arr
	vec = []
	for i in range(0,len(arr)):
		if row_check(arr[i],h):
			vec.append(i)
	arr = list(map(list,zip(*arr)))
	for i in range(0,len(arr)):
		if row_check(arr[i],h):
			arr[i] = [a+1 for a in arr[i]]
	arr = list(map(list,zip(*arr)))
	for i in vec:
		for j in range(0,len(arr[i])):
			if arr[i][j] == h:
				arr[i][j] += 1
	for i in range(0,len(arr)):
		for j in range(0,len(arr[i])):
			if arr[i][j] == h:
				return False
	return True

inp = open("file1.txt").read().splitlines()
outp = open("out1.txt","w")

i = 1
c = 1
for i in range(0,int(inp[0])):
	arr = []
	foo = inp[c].split()
	c += 1
	for j in range(0,int(foo[0])):
		bar = inp[c].split()
		arr.append(list(map(int,bar)))
		c += 1
	suc_bool = True
	for k in range(1,100):
		if not isposs(k):
			suc_bool = False
			break
	if suc_bool:
		s = ": YES\n"
	else:
		s = ": NO\n"
	outp.write("Case #"+str(i+1)+s)
