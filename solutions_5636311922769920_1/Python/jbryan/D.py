from math import *
from itertools import accumulate

input_file = open('D-large.in.txt','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('D.txt','w')

debug=1

###################

while case_num<=num_cases:
    K,C,S=map(int,lines[case_num].split(' '))
    #J=int(lines[case_num].split(' ')[1])

    #if debug: print('K, C, S: ',K,C,S)
    
    output_text += ('Case #'+str(case_num)+': ')
    if K/C > S:
        output_text += 'IMPOSSIBLE\n'
    else:
        num_to_test = ceil(K/C)  #guaranteed <= S
        tiles = []
        for i in range(num_to_test):
            t=1  #tile nums start at 1
            for j in range(C):
                orig_tile = (i*C+j)%K  #tile from original K being accounted for
                t += orig_tile * (K**j)
            tiles.append(t)
        output_text += ' '.join(map(str,tiles)) + '\n'

    case_num += 1


if debug: print('\n'+output_text)
output_file.write(output_text)
input_file.close()
output_file.close()
