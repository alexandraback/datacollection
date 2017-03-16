from math import *
from itertools import accumulate

input_file = open('C-sample.in','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('C.txt','w')

debug=1

###################

def factor(coin):
    factors = []
    for base in range(2,11):
        #print(int(coin,base))
        x = int(coin,base)

        factor = 0

        #if debug==2: print(ceil(sqrt(x))+1)

        for i in range(2,1000):  #range(2,ceil(sqrt(x))+1):
            if x%i==0:
                factor = i
                factors.append(i)
                break
        
        if not factor:
            return False

    return factors

while case_num<=num_cases:
    N=int(lines[case_num].split(' ')[0])
    J=int(lines[case_num].split(' ')[1])

    output_text += ('Case #'+str(case_num)+':\n')

    coin_count=0
    for i in range(2**(N-2)):
        middle = bin(i)[2:]
        coin = '1'+'0'*(N-2-len(middle))+middle+'1'
        factors = factor(coin)
        if factors:
            output_text += (coin+' ' + (' '.join(map(str,factors))) + '\n')
            coin_count += 1
        if coin_count == J:
            break

    case_num += 1


if debug: print('\n'+output_text)
output_file.write(output_text)
input_file.close()
output_file.close()
