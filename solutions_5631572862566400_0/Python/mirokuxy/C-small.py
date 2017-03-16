



List = []
Visited = []
Max = 0

friend = []

def updateMax(count):
	global Max
	#Max = Max if Max > count else count

	if count > Max:
		#print 'Max :', List
		Max = count

def dfs(index, current):
	global List, Visited, Max
	global friend

	if Visited[current] == 1: 
		return

	List[index] = current
	Visited[current] = 1

#	print List

	next = friend[current]

	if Visited[next] == 0:
		dfs(index+1, next)
	elif List[index-1] == next:
		updateMax(index)

		for x in range(1, len(friend)):
			dfs(index+1, x)
	elif List[1] == next:
		updateMax(index)
	else:
		pass

	Visited[current] = 0

def process():
	global List, Visited, Max
	global friend

	Max = 0

	for x in range(1, len(friend)):
		List = [0] * len(friend)
		Visited = [0] * len(friend)

		dfs(1, x)

	return Max


T = int(raw_input())

for case in range(1,T+1):
	N = int(raw_input())

	line = raw_input()
	line = line.strip().split(' ')
	friend = [int(x) for x in line]
	friend.insert(0,0)

	#print friend

	res = process()

	print "Case #%d: %d" % (case, res)



