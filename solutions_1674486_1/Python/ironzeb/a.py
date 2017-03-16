import copy 
f = open('a-large.txt')
outstr = ''
outf = open('a-large.out', 'w')
T = int(f.readline())

class Node(object):
    def __init__(self, num):
    	self.n = num
        self.children = []
        self.visited = False

    def add_child(self, obj):
        self.children.append(obj)

diamond = False

def visited(node):
	global diamond
	root = node
	if root.visited or diamond: 
		diamond = True
		return True
	root.visited = True
	return False

q = []

def follow():
	global q
	if not q:
		return
	root = q.pop()
	if visited(root):
		return
	for child in root.children:
		q.append(child)
		

for case in range(1,T+1):
	roots = []
	line = f.readline().strip()
	N = int(line)
	nodes = [Node(n) for n in range(0,N)]

	for n in range(0, N):
		node = nodes[n]

		line = f.readline().strip().split(' ')
		num_classes = int(line[0])	
		class_nums = map(int, line[1:])
		#print class_nums
		for num in class_nums:
			nodes[num-1].add_child(node)
		if num_classes == 0:
			roots.append(node)

	for node in nodes:
		for node2 in nodes:
			node2.visited = False
		diamond = False
		q = [node]
		while q:
			follow()
		if diamond:
			output = 'Yes'
			break
		else:
			output = 'No'

	outstr = "Case #%d: %s\n" % (case, output)

	# output
	print outstr,
	outf.write(outstr)

f.close()
outf.close()
