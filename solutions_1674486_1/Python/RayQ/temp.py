import sys
sys.setrecursionlimit(1000000)

class Node:
	def __init__(self,num):
		self.id = num
		self.parents = []
		self.children = []
	
	def add_parent(self,Node):
		self.parents.append(Node)
		
	def get_parents(self):
		return self.parents
		
	def add_child(self,Node):
		self.children.append(Node)
		
	def get_children(self):
		return self.children
	
	def diamond_check(self,in_set):
		#If one child contains Node x as a child, and another child contains or is Node x, then
		#diamond inheritance exists.
		in_path = in_set
		
		in_path.add(self)
		for child in self.children:
			if child in in_path:
				return True
			in_path.add(child)
			if child.diamond_check(in_path):
				return True
		
		return False
				


if (len(sys.argv) > 1):
	file = open(sys.argv[1],'r')
	outfile = open("output", 'w')
	cases = file.readline()
	cases = int(cases)
	iters = 0
	
	
	while(iters < cases):
		nodes = []
		num_of_nodes = file.readline()
		num_of_nodes = int(num_of_nodes)
		
		#Create nodes
		for i in xrange(num_of_nodes):
			nodes.append(Node(i))
		
		#Assign parents
		for i in xrange(num_of_nodes):
			inherit = file.readline()
			inherit = inherit.split(' ')
			inherit = [int(x) for x in inherit]
			for id in inherit[1:]:
				nodes[i].add_parent(nodes[id-1])
				nodes[id-1].add_child(nodes[i])
				
		#Diamond check all nodes, until one returns true or no diamond
		#inheritance is found
		
		outfile.write("Case #" + str(iters+1) + ": ")
		found = False
		for node in nodes:
			if node.diamond_check(set()):
				outfile.write("Yes \n")
				found = True
				break
		if not found:
			outfile.write("No \n")
			
		iters += 1

	file.close()
	outfile.close()
		
		