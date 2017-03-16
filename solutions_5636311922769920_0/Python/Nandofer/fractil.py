'''
Created on Apr 9, 2016

@author: fernandomendez
Fractil problem
'''
import argparse
import sys



def fractil(line):
    fiel = [int(x) for x in line.split()]
    patlen = fiel[0]
    compl = fiel[1]
    students = fiel[2]
    if students >= patlen:
        posit = list()
        for idx in range(1, min(patlen,students)+1):
            posit.append(str(idx))
        return ' '.join(posit)
    return None

parser = argparse.ArgumentParser(description='''Jamcoin''',  epilog='')
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

    sol = fractil(line)
    outFile.write('Case #'+str(case)+": "+str(sol)+"\n")
