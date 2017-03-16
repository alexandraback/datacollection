import unittest,sys, re
from collections import deque
from decimal import *
import  math

class Level:
    def __init__(self, level, difficulty, stars):
        self.level = level
        self.difficulty = difficulty
        self.stars = stars

def getProblemAnswer(S):
    word = S.split(' ')[0]
    alter_word = word
    altered_letters = 0
    n = int(S.split(' ')[1])
    count = long(0)
    letters = ['a', 'e', 'i', 'o', 'u']
    subsequences = re.split('|'.join(letters), word)
    positions = [0 for t in subsequences if len(t) >= n]
    solutions = [t for t in subsequences if len(t) >= n]
    for j, s in enumerate(solutions):
        i = alter_word.index(s) + altered_letters
        positions[j] = i
        alter_word = alter_word[i - altered_letters + len(s):]
        altered_letters = i + len(s)
    
    print solutions
    print positions

    if solutions:
        count += 1
    for j, s in enumerate(solutions):
        i = positions[j]
        left = positions[j] + 1
        if j > 0:
            left -= positions[j-1]
        right = len(word) - i - len(s) + 1
        if j < len(solutions) - 1:
            right -= len(word) - positions[j+1] - len(solutions[j-1])
        mult = 1
        if len(s) > n:
            mult = long(math.factorial(len(s))) / long(math.factorial(n)) * long(math.factorial(len(s) - n))
        print right
        count += (left * right) * (mult) - 1
    return count





class Tests(unittest.TestCase):

    def test_unit(self):
        self.assertEqual(getProblemAnswer('quartz 3'),4)
        self.assertEqual(getProblemAnswer('straight 3'),11)
        self.assertEqual(getProblemAnswer('gcj 3'),1)
        self.assertEqual(getProblemAnswer('tsetse 2'),11)
        self.assertEqual(getProblemAnswer('gcj 2'),3)
        self.assertEqual(getProblemAnswer('gcjt 2'),24)
        #self.assertEqual(getProblemAnswer('thwnhqgnkxbpvplpdoenpavizqqpprifyysbtynbrmmkqvwcwtpjbftzfslrgmvzflyedhwvodcsxyaplcylhlhjzpxbxsobzwub 9'),24)
        self.assertEqual(getProblemAnswer('jnwbsqullonghfcqukgipexulxcucyeueohyzdugqriioldueesuuaouasegiinpiuuovmbuohospqwffakbwzgc 4'),24)
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
        number_lines = 1#int(lines.popleft()) #1 ##TODO
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