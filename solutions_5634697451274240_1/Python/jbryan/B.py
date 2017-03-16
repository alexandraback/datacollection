from math import *
from itertools import accumulate

input_file = open('B-large.in.txt','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('B.txt','w')

debug=0

###################

while case_num<=num_cases:
    cakes=lines[case_num]
    
    output_text += ('Case #'+str(case_num)+': ')
    if debug: print(cakes)

    num_cakes = len(cakes)
    orientation = '+'
    flips = 0
    for i in range(num_cakes-1,-1,-1):
        if cakes[i] != orientation:
            flips += 1
            orientation = cakes[i]
    output_text += str(flips)+'\n'

    case_num += 1


if debug: print('\n'+output_text)
output_file.write(output_text)
input_file.close()
output_file.close()
