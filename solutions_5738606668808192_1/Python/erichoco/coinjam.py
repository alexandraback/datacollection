#!/usr/bin/python

import sys, datetime
import itertools
import string
import math
import random

# Import third-party libraries (optional)
# https://code.google.com/p/gmpy/
#import gmpy

def solve(input_num):
    '''
    ' Write your code here
    ' Return solution
    '''
    length = input_num[0]
    limit = input_num[1]

    answers = '\n'

    bitstr_rest = []
    for s in itertools.product('01', repeat=length-2):
        if s.count('1') % 2 == 0:
            bitstr = '1' + ''.join(s) + '1'
            ans = findDivisors(bitstr)
            if ans:
                answers += ans
                limit -= 1
                if limit == 0:
                    break

        else:
            bitstr_rest.append('1' + ''.join(s) + '1')

    if limit != 0:
        for s in bitstr_rest:
            ans = findDivisors(s)
            if ans:
                answers += ans
                limit -= 1
                if limit == 0:
                    break

    # print limit
    return answers

def findDivisors(bitstr):

    divisors = []
    for base in xrange(2, 11):
        num = int(bitstr, base)
        if num % (base+1) != 0:
            return ''
        divisors.append(str(base+1))

        # # for i in xrange(2, int(math.sqrt(num)) + 1):
        # for i in xrange(2, 100):
        #     if base == 2 and i > 3:
        #         return ''
        #     if num % i == 0:
        #         divisors.append(str(i))
        #         # time = datetime.datetime.now() - start
        #         # print time
        #         break
        # else:
        #     return ''

    return '%s %s\n' % (bitstr, ' '.join(divisors))

def test():
    pass

def main():
    # Test if at least input file is provided
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    # Start time
    timestart = datetime.datetime.now()

    # Open input and output files
    try:
        inputFile = open(sys.argv[1])
    except:
        print 'Failed to read input file %s' % sys.argv[1]
        return
    try:
        outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    except:
        print 'Failed to create output file %s' % sys.argv[2]
        return

    # First line of input file usually is the number of test cases.
    # Adjust if necessary
    testCases = int(inputFile.readline().strip())

    # Display number of test cases and output file name
    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    # Loop through all test cases
    for testCaseNumber in range(1, testCases+1):

        '''
        ' Edit this section
        ' Read Test Case input and adjust output format
        ' Uncomment the necessary parts and adjust to your needs
        '''

        '''
        ' Integers
        '''
        # Read an integer
        # n = int(inputFile.readline().strip())


        # Read a list of integers
        n_list = map(int, inputFile.readline().strip().split())

        # Read a matrix of integers
        #n_matrix = []
        #for i in range(n):
        #    n_matrix.append(map(int, inputFile.readline().strip().split()))

        '''
        ' Floats
        '''
        # Read a float
        #f = float(inputFile.readline().strip())

        # Read a list of flots
        #f_list = map(float, inputFile.readline().strip().split())

        '''
        ' Strings
        '''
        # Read a string
        # s = inputFile.readline().strip()

        # Read a list of strings
        # s_list = inputFile.readline().strip().split()

        '''
        ' Return string.
        ' Add necessary arguments to solve() function
        ' Adjust return type if necessary (%s for string, %f for floats, etc)
        '''
        string = 'Case #%d: %s' % (testCaseNumber, solve(n_list))

        '''
        ' End of edit section
        '''

        # print return string and write it to output file
        print string
        if outputFile:
            outputFile.write(string + '\n')

    # Print some final info: output file name and execution time
    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    # Close input and output files
    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
    # test()