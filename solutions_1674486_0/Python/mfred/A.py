input = open('small.in', 'r').read()
# input="""4
# 3
# 1 2
# 1 3
# 0
# 5
# 2 2 3
# 1 4
# 1 5
# 1 5
# 0
# 3
# 2 2 3
# 1 3
# 0
# 4
# 2 2 3
# 0
# 0
# 2 2 3"""


lines = input.split("\n")

cur_line = 1
i=1

def circuit_dfs(start, status, inherits):
	if status[start]:
		return True
	
	status[start] = True
	
	voisins = []
	for j in range(0,len(status)):
		if inherits[start][j]:
			voisins += [j]
	
	r = False
	for v in voisins:
		if status[v]:
			return True
		else:
			r = r or circuit_dfs(v,status,inherits)
		if r:
			break
	return r
	
	
while cur_line<len(lines)-1:
	line = lines[cur_line]
	N = int(line)
	
	inherits = [[False for j in range(0,N)] for k in range(0,N)]
	# inherits[j][k] == True ssi j herite de k
	cur_line +=1
	for j in range(0,N):
		line = lines[cur_line]
		info = line.split(" ")
		parents = int(info[0])
		for k in range(1,parents+1):
			inherits[j][int(info[k])-1] = True
		cur_line += 1
			
	# print inherits
	
	# symetriser
	# for j in range(0,N):
	# 		for k in range(0,N):
	# 			if inherits[j][k]:
	# 				inherits[k][j] = True
	res = False
	for j in range(0,N):
		status = [False for k in range(0,N)]
		dfs_r = circuit_dfs(j, status, inherits)
		# print j,dfs_r
		res = res or dfs_r
	
	if res:
		r = "Yes"
	else:
		r = "No"
	print "Case #"+str(i)+": "+r
	i += 1



def stringArrayToVector(arr):
	res = []
	for s in arr:
		res += [int(s)]
	return res