'''
Created on Apr 9, 2016

@author: fernandomendez
Fractil problem
'''
import argparse
import sys
import math

def generate_powers (base, compexity):
    pows = dict()
    pows[0] = 1
    for idx in range(compexity):
        pows[idx+1] = pows[idx]*base
    return pows

def complete_powers (pows, compexity):
    base = pows[1]
    keys = pows.keys()
    keys.sort()
    for idx in range(keys[-1],compexity):
        pows[idx+1] = pows[idx]*base
    return pows 



def fractil(line, powers):
    fiel = [int(x) for x in line.split()]
    patlen = fiel[0]
    compl = fiel[1]
    if compl > patlen:
        compl = patlen
    students = fiel[2]
    if students >= patlen:
        posit = list()
        for idx in range(1, min(patlen,students)+1):
            posit.append(str(idx))
        return ' '.join(posit)
    elif students * compl < patlen:
        return 'IMPOSSIBLE'
    if patlen not in powers:
        powers[patlen] = generate_powers(patlen,compl)   # generates the initial dictionary of powers
    elif compl not in powers[patlen]:
        complete_powers(powers[patlen],compl )  # completes a dictionary with remaining powers
    # done fixing he powers of the base
    
    
    student_tile_range = list()
    for tile_idx in range(patlen/compl+1):
        if tile_idx*compl+1 <= patlen:
            student_tile_range.append([tile_idx*compl+1, min(patlen,(tile_idx+1)*compl )])
#     print patlen, compl, students
#     print student_tile_range
#     print powers.keys()
    ### Have obtained the range for each student
    checked_tiles = list()
    for idx in range(len(student_tile_range)):
        checked_tiles.append(add_tile(student_tile_range[idx], powers[patlen], compl))
        ## range of tiles
        ## powers dictionary for the given base
        ## complexity
    return ' '.join([str(x) for x in checked_tiles])
    return None



def add_tile(std_tile_range, pows,complexity):
    posit = 0 
    for line_idx in range(std_tile_range[0],std_tile_range[1]+1):
#         print line_idx
        posit += (line_idx-1) * pows[complexity-line_idx+std_tile_range[0]-1]
#     print posit
    return posit+1



parser = argparse.ArgumentParser(description='''Fractil''',  epilog='')
parser.add_argument('input',  help='input file', )
parser.add_argument('output', help='output file')
args = parser.parse_args()


powers =dict()    #dictionary containing all the relevant powers

inFile = open (args.input)
outFile = open (args.output, 'w')
line = inFile.readline()
line= line.strip()
ncases = int(line)
for case in range(1, ncases+1):
    line = inFile.readline()
    line = line.strip()

    sol = fractil(line, powers)
    outFile.write('Case #'+str(case)+": "+str(sol)+"\n")
# print powers
