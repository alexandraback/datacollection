class Tree():
	def __init__(self, number):
		self.number = number
		self.children = []
		self.classList = [number]
	
	def addChild(self, child):
		self.children.append(child)

	
		
	def getClassList(self):
		myClassList = [self.number]
		for child in self.children:
			myClassList.extend(child.getClassList())
		return myClassList

def calculate(numClasses,classList):
	#classList = strings, numClasses = ints
	#print numClasses
	trees = []
	for child in range(numClasses):
		trees.append(Tree(child))
	
	for i in range(numClasses):
		inheritanceList = classList[i].split()
		m = int(inheritanceList[0])
		tree = trees[i]
		for j in range(m+1)[1:]:
			#print "i:", i, "  j=",j
			trees[int(inheritanceList[j])-1].addChild(tree)
			
	
	for tree in trees:
		#print tree.children
		if len(tree.children) > 1:
			childList = tree.getClassList()
			if len(childList) > len(list(set(childList))):
				return "Yes"
			
		
	
		
	
	return "No"#Yes or No
	


if __name__ == "__main__":
	import sys
	file = open(sys.argv[1],'r')
	numTests = file.readline()
	for case in range(int(numTests)):
		numClasses = int(file.readline())
		classList = []
		for testclass in range(numClasses):
			classList.append(file.readline())
		string = "Case #"+str(case+1)+": "+calculate(numClasses, classList)
		string = string.rstrip()
		string = string.lstrip()
		print string