import sys

def main(inp, out):
    input = open(inp)
    output = open(out,'w')
    caseString=input.readline()
    if caseString[-1:]=='\n':
	caseString=caseString[:-1]
    numCases=int(caseString)
    res=""
    for i in range(numCases):
	numNodes=input.readline()	
	if numNodes[-1:]=='\n':
		numNodes=numNodes[:-1]	
	numNodes = int(numNodes)
	paths = []
	for j in range(numNodes):
		line=input.readline()
		if line[-1:]=='\n':	
			line = line[:-1]
		newPoints = line.split(" ")
		path = []
		for k in newPoints[1:]:
			path.append(int(k)-1)
		paths.append(path)
	res+="Case #"+str(i+1)+": "        	
	res+=diamondPath(paths)
	res+="\n"
    output.write(res)
    output.close()
	
	
def diamondPath(paths):
	for i in range(len(paths)):
		seen = [0]*len(paths)
		start = i
		currentPath = []
		fringe = [start]		
		while fringe != []:
			current = fringe.pop()
			seen[current]+=1
			if seen[current] > 1:
				return "Yes"
			path = paths[current]
			for node in path:
				fringe.append(node)
	return "No"
		
	
	
			
	
	
	
	
if __name__=='__main__':
    main(sys.argv[0], sys.argv[1])

def test(input, out):
    main(input, out)