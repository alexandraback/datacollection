import sys
import math

def main(filename):
	result = ''
	file = open(filename)
	numberOfTests = int(file.readline())
	for i in range(numberOfTests):
		nm = [int(num) for num in file.readline().split()]
		x = nm[0]
		y = nm[1]
		result += 'Case #%d: %s\n' % (i+1,solvePogo(x, y))
	file.close()
	return result
	
def solvePogo(x, y):
	result = ''
	currentX = 0
	currentY = 0
	jump = 1
	left = True
	while currentX != x or currentY != y:
		if currentY != y and abs(y) == jump:
			if y>0:
				result += 'N'
				currentY += jump
			if y<0:
				result += 'S'
				currentY -= jump
			if currentX > x:
				left = False
			else:
				left = True
		else:
			if left:
				currentX -= jump
				result += 'W'
				left = False
			else:
				currentX += jump
				result += 'E'
				left = True			
		jump += 1
	return result
	
if __name__ == '__main__':
	if len(sys.argv) < 3:
		print 'Not enough files specified'
		sys.exit(1)
	inputfilename = sys.argv[1]
	outputfilename = sys.argv[2]
	result = main(inputfilename)
	outputfile = open(outputfilename, 'w')
	outputfile.write(result)
	outputfile.close()
	print result