import unittest,sys, re
from collections import deque
from decimal import *

class Tribe:
    def __init__(self, input, id):
        self.id = id
        self.d = int(input.split(' ')[0])
        self.n = int(input.split(' ')[1])
        self.w = int(input.split(' ')[2])
        self.e = int(input.split(' ')[3])
        self.s = int(input.split(' ')[4])
        self.dd = int(input.split(' ')[5])
        self.dp = int(input.split(' ')[6])
        self.ds = int(input.split(' ')[7])

def getProblemAnswer(S):
    print S
    tribes = []
    for i, t in enumerate(S):
        tribes.append(Tribe(t, i))

    wall = [0 for i in range(3000)]
    center = 1500
    number_of_breach = 0
    
    s_tribes = tribes
    while s_tribes:
        s_tribes = sorted(s_tribes, key=lambda x: x.d)
        current_day = s_tribes[0].d
        new_wall = wall

        for tribe in s_tribes:
            if tribe.d == current_day:
                has_breached = False
                for i in range(tribe.w, tribe.e):
                    if wall[center + i] < tribe.s:
                        has_breached = True
                        new_wall[center + i] = max(tribe.s, new_wall[center + i])
                if has_breached:
                    number_of_breach += 1
                tribe.n -= 1
                if tribe.n == 0:
                    s_tribes.remove(tribe)
                tribe.d += tribe.dd
                tribe.s += tribe.ds
                tribe.w += tribe.dp
                tribe.e += tribe.dp
        wall = new_wall



    return number_of_breach



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
        number_lines = int(lines.popleft()) #1 ##TODO
        for line in range(number_lines):
            input.append(lines.popleft())
        print input
        result = getProblemAnswer(input) ##TODO
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