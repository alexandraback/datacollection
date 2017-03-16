import unittest,sys, re
from collections import deque
from decimal import *


def getProblemAnswer(S):
    print S
    positionX = 0
    positionY = 0
    pogo = 0
    goalX = int(S.split(' ')[0])
    goalY = int(S.split(' ')[1])
    path = ''
    direction = ''

    while(positionX != goalX or positionY != goalY):
        #import pdb; pdb.set_trace()
        pogo += 2 #1
        if positionY > goalY:
            direction = 'NS'
            positionY -= 1

        elif positionY < goalY:
            direction = 'SN'
            positionY += 1

        elif positionX > goalX:
            direction = 'EW'
            positionX -= 1

        elif positionX < goalX:
            direction = 'WE'
            positionX += 1
        else:
            break

        path += direction

    print len(path)
    return path



class Tests(unittest.TestCase):

    def test_unit(self):
        self.assertEqual(getProblemAnswer('3 4'),'ENWSEN')
        self.assertEqual(getProblemAnswer('-3 4'),'ENSWN')



	def test_sample(self):
		path = 'A-test'
		f = open(path + '.out')
		lines = f.readlines()
		f.close()
		f = open(path + '.expected.out')
		expected_lines = f.readlines()
		f.close()
		self.assertEqual(lines, expected_lines)




def main(arg1):
    print 'opening ' + arg1
    f = open(arg1 + '.in')
    lines = f.readlines()
    f.close()
    lines = deque([case[:-1] for case in lines])
    #print [case for case in lines]
    number_test_cases = int(lines.popleft())

    output = ''
    print 'a total of ' + str(number_test_cases) + ' cases'

    for case_number in range(number_test_cases):
        input = []
        number_lines = 1# int(lines.popleft()) #1 ##TODO
        for line in range(number_lines):
            input.append(lines.popleft())
        print input
        result = getProblemAnswer(input[0]) ##TODO
        if result is -1 : ##TODO
            result = 'Too Bad'
    	output += 'Case #' + str(case_number + 1) + ': ' + str(result) + '\n' 
        print 'Case #' + str(case_number + 1) + ' done'
    print output
    

    should_write = False
    should_write = True
    if should_write:
    	write_answer(arg1 + '.out', output)
    else:
    	print 'NOT WRITING ANYTHING \n'


def write_answer(name, output):
	f = open(name, 'w+')
	lines = f.write(output)
	f.close()
	print 'ANSWERS WRITTEN\n'



if __name__ == '__main__':
	if len(sys.argv) == 2:
		sys.exit(main(sys.argv[1]))
	else:
		unittest.main()