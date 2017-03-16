import sys


def unWrap(mat):
	return [ el for row in mat for el in row ]

def transpose(mat):
	return map(list, zip(*mat))	

def lineLegit(line,height):
	return max(line)==height


def elementLegit(pattern,transPattern,x,y,height):
	return lineLegit(pattern[x],height) or lineLegit(transPattern[y],height)


def patternLegit(pattern):
	print pattern
	
	transPattern = transpose(pattern)
	
	heights = sorted(set(unWrap(pattern)))
	
	for height in heights:
		for indexI,line in enumerate(pattern):
			for indexJ,element in enumerate(line):
				if pattern[indexI][indexJ]==height and not elementLegit(pattern,transPattern,indexI,indexJ,height):
					print 'Not legit due to element %d,%d with height %d' % ( indexI+1,indexJ+1,height )
					return False
	return True

	
def main():

	with open(sys.argv[1]) as inFile:
		T = int(inFile.readline())
		maps = []
		for i in range(T):
			maps.append([])
			N , M = map(int,inFile.readline().split())
			for j in range(N):
				maps[i].append(map(int,inFile.readline().split()))

	#~ for i in maps:
		#~ for j in i:
			#~ print j
		#~ print ''

	solutions=[]
	for pattern in maps:
		if patternLegit(pattern):
			solutions.append('YES')
		else:
			solutions.append('NO')

	#~ pattern = [ [1,5,3] , [1,2,2] , [1,5,3]  ]

	#~ print patternLegit(pattern)

	

	with open(sys.argv[2],'w') as outFile :	
		for index,solution in enumerate(solutions):
			print solution
			outFile.write( 'Case #' + str(index+1) + ': ' + solution + '\n')		
		
if __name__ == "__main__":
    main()
