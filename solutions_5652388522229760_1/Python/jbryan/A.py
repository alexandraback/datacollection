from math import *
from itertools import accumulate

input_file = open('A-large.in.txt','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('A.txt','w')

debug=0

###################

digits = [False]*10

def digit_check(x):
    s = str(x)
    l = len(s)
    for i in range(l):
        digits[int(s[i])] = True
        
    return (digits == [True]*10)

while case_num<=num_cases:
    N=int(lines[case_num])
    
    output_text += ('Case #'+str(case_num)+': ')

    if N==0:
        output_text += 'INSOMNIA\n'
    else:
        digits = [False]*10
        for i in range(1,101):
            x = i*N
            if digit_check(x):
                output_text += str(x)+'\n'
                break
    
    case_num += 1


if debug: print('\n'+output_text)
output_file.write(output_text)
input_file.close()
output_file.close()
