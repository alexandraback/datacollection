'''
Created on Apr 8, 2016

@author: flmendez
'''

import argparse
import sys




def count_sheep(line):
    digitset = set()
    basenum = int(line)
    lastnum = 0
    numlen = len(str(basenum))
    if basenum == 0:
        return 'INSOMNIA'
        
    while lastnum < 100**numlen*basenum:
        lastnum += basenum
        newdigits = list(str(lastnum))
        print newdigits
        print digitset
        for dig in newdigits:
            digitset.add(dig)
        if len(digitset) ==10:
            return lastnum
    return 'INSOMNIA'

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
    sol = count_sheep(line)
    outFile.write('Case #'+str(case)+': '+str(sol)+'\n')

