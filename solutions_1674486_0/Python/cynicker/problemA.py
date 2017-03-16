class node:
	def __init__(self, value):
		self.value = value + 1
		self.visited = False
		self.parents = []
	def visit(self):
		self.visited = True

def traverse(clazz):
#	print "node #", clazz.value
	if clazz.visited == True:
		return "Yes"
	else:
		clazz.visit()
		for parent in clazz.parents:
			if traverse(parent) == "Yes":
				return "Yes"
		return "No"

data = open(".\A-small-attempt2.in", "r")
num_of_cases = int(data.readline())
for i in range(1,num_of_cases+1):
	start_points = []
	clazzes = []
	num_of_clazzes = int(data.readline())
	ret = "No"
	for j in range(num_of_clazzes):
		clazzes.append(node(j))
	for j in range(num_of_clazzes):
		parents = map(int, data.readline().split())
		parents = parents[1:]
		if len(parents) > 1:
			start_points.append(clazzes[j])
		for k in parents:
			clazzes[j].parents.append(clazzes[k-1])
			#print "parents of ", j+1, ":", clazzes[j].parents
	for point in start_points:
		if traverse(point) == "Yes":
			ret = "Yes"
			break
		for j in clazzes:
			j.visited = False
	print "Case #%d:" % (i), ret
