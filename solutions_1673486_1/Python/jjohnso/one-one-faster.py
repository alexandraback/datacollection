'''
Created on Apr 27, 2012

@author: Josh
'''
import string
import operator


def solve(input_file):
    line_one = map(int, string.split(input_file.readline()))
    line_two = map(float, string.split(input_file.readline()))
    num_typed = line_one[0]
    num_total = line_one[1]
    
    expected_give_up = num_total + 2
    
    min_expected = float(expected_give_up)
    
    prob_right = 1
    
    for i in range(0, num_typed + 1):
        #print 'i', i
        
        #print 'probs', prob_right
        min_typed =  (num_total - i + 1) + (num_typed - i)
        #print 'min_typed', min_typed
        expected_wrong_extra = (1 - prob_right) * (num_total + 1)
        expected = min_typed + expected_wrong_extra
        min_expected = min(expected, min_expected)
        #print 'expected', expected
        print i
        if i < len(line_two):
            prob_right = prob_right * line_two[i]
    answer = min_expected
    print 'answer', answer
    return answer


def print_answer(num, answer, out):
    out.write ('Case #%s: %s\n' % (num, answer))
    

if __name__ == '__main__':
    FILE = 'one'

    input_file = open ('%s.in' % (FILE,), 'r')
    output_file = open('%s.out' % (FILE,), 'w')
    
    num_cases = int(input_file.readline())
    
    for i in range(1, num_cases+1):
        print '\n', i, '============================================'
        answer = solve(input_file)
        print_answer(i, answer, output_file)
    
    output_file.close()