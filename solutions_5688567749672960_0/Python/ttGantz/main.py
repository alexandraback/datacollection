__author__ = 'radykov'
import sys
import operator
from fractions import gcd

def read_input():
    #file = open('input.txt', 'r')
    #file = open('B-large-practice.in', 'r')
    file = open('A-small-attempt1.in', 'r')
    lines = file.read().split('\n')
    if lines[-1] == '':
        del lines[-1]
    return lines

def process_output(outfile, output, i):
    out_str =  'Case #' + str(i) + ": " + str(output) + '\n'
    outfile.write(out_str)

def process_inputs(inputs):
    outfile = open('outfile.txt', 'w')
    for i in range(1, len(inputs)):
        output = process_input(int (inputs[i]))
        process_output(outfile, output, i)
        print i
    outfile.close()

def process_input(number):
    final = [100000000000000]*(number+1)
    final [1] = 1
    for i in range(1, number):
        current = final[i]
        next = current+1
        if  next  < final[i+1]:
            final[i+1] = next
        string = str(i)
        string.replace("0", "")
        reverse = string[::-1]
        newint = int(reverse)
        if newint <= number:
            if next < final[newint]:
                final[newint] = next
    return final[number]


inputs = read_input()
process_inputs(inputs)
