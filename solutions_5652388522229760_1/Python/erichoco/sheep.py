#!/usr/bin/python

'''
' Python template for Google Code Jam
' Version 0.2
'
' By urupica (Kevin Bauer) urupica@gmail.com
'
' Usage: $ ./google.py inputFile [outputFile]
' Script reads from inputFile and writes to outputFile (optional)
'
' Use at own risk. Use the code for whatever you like:)
'''

# Import necessary libraries to read command line arguments and calculate execution time
import sys, datetime
import sets
import random

# Import third-party libraries (optional)
# https://code.google.com/p/gmpy/
#import gmpy

def solve(start_num):
    '''
    ' Write your code here
    ' Return solution
    '''

    multi = 0
    s = sets.Set('0123456789')

    while True:
        multi = multi + 1
        num = start_num * multi
        if multi > 1 and num == start_num:
            return 'INSOMNIA'

        s = s.difference(str(num))
        if not s:
            return num

def test():
    for i in range(1000001):
        # test_num = int(random.random() * 100000000)
        ans = solve(i)
        print 'Case #%d: %s' % (i, ans)

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
        start_num = int(inputFile.readline().strip())


        # Read a list of integers
        #n_list = map(int, inputFile.readline().strip().split())

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
        string = 'Case #%d: %s' % (testCaseNumber, solve(start_num))

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