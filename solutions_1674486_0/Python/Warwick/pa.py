class node:
	def __init__(self):
		pass
		
	def add_nodes(self,nodes):
		self.inherit = nodes
	
	def dfs(self):
		if self.inherit ==[]:
			return set([self])
		else:
			s = set([self])
			for i in self.inherit:
				y = i.dfs()
				if y == True:
					return y
				else:
					if len(s.intersection(y))>0:
						return True
					else:
						s = s.union(y)
			return s
			
def handle_input(lines):
	lines = map(lambda x: x[:-1],lines)
	lines.reverse()
	t = int(lines.pop())
	for j in range(t):
		n = int(lines.pop())
		nodes = []
		for i in range(n):
			nodes.append(node())
		for i in range(1,n+1):
			s = map(int,lines.pop().split(" "))
			m = s[0]
			inh = []
			for x in s[1:]:
				inh.append(nodes[x-1])
			nodes[i-1].add_nodes(inh)
		ans = False
		for i in range(n):
			if nodes[i].dfs()==True:
				ans = True
				break
		handle_output(j+1,ans)
		
	
	
	
	
def handle_output(case,answer):
	if answer==True:
		print "Case #",case,": Yes"
	else:
		print "Case #",case,": No"
	
	


	
fd = file('input.in')
handle_input(fd.readlines())
fd.close()


