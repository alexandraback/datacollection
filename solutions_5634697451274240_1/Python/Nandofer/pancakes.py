'''
Created on Apr 8, 2016

@author: flmendez
Revenge of pancakes
'''


import argparse
import sys




def flip(line):
    values = list(line)
    flips = 0
    for i in range(len(values)-1):
        if values[i] != values[i+1]:
            flips +=1
    if values[-1]=='+':
        return flips
    else:
        return flips+1
    



parser = argparse.ArgumentParser(description='''Put title''',  epilog='')
parser.add_argument('input',  help='input file', )
parser.add_argument('output', help='output file')
args = parser.parse_args()


inFile = open (args.input)
outFile = open (args.output, 'w')


line = inFile.readline()
line= line.strip()
ncases = int(line)


for case in range(1, ncases+1):
    line = inFile.readline()
    line = line.strip()
    sol = flip(line)
    outFile.write('Case #'+str(case)+': '+str(sol)+'\n')

