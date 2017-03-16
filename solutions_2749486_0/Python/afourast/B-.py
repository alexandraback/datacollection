import sys
from math import sqrt , floor , ceil
from math import log , exp
 
 
def solveCaseDummy(x,y):
	ans = ''
	if x>0:
		s='WE'
	else:
		s='EW'
	
	for i in xrange(abs(x)):
		ans+=s
		
	if y>0:
		s='SN'
	else:
		s='NS'
	
	for i in xrange(abs(y)):
		ans+=s

	return ans
				
def main():
	with open(sys.argv[1]) as inFile:
		cases = []
		T = int(inFile.readline())
		for i in range(T):
			cases.append(map(int,inFile.readline().split()))

	print cases
	
	solutions=[]
	
	for case in cases:
		x,y = case
		solutions.append( solveCaseDummy(x,y) )
	
	

		
	with open(sys.argv[2],'w') as outFile :	
		for index,solution in enumerate(solutions):
			print solution
			outFile.write( 'Case #' + str(index+1) + ': ' + str(solution) + '\n')

if __name__ == "__main__":
    main()
