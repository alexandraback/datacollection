import sys
import math
import numpy # http://www.numpy.org/
import string
import tkinter as tk
from tkinter.filedialog import askopenfilename
from itertools import product # https://docs.python.org/2/library/itertools.html

root = tk.Tk()
root.withdraw()
filename = askopenfilename()

fInput = open(filename, 'r')
fOutput = open(filename.replace('.in', '.txt'), 'w+')

cases = int(fInput.readline())

def BaseConvert(value, base):
    number = 0
    power = 1

    for i in range(len(value)):
        if(value[-1-i] == 1):
            number += power
        power *= base
    return number

for t in range(cases):
    N = 32
    J = 500
    primes = [2,3,5,7,11,13,17,19,23,29,31,37]
    divisor = [None]*9
    count = 0
    print('Case #1:')
    fOutput.write('Case #1:\n')
    for i in product(range(2),repeat=N-2):
        flag = 1
        for j in range(2,11):
            if (any(BaseConvert([1]+list(i)+[1],j) % k is 0 for k in primes)):
                for l in range(len(primes)):
                    if (BaseConvert([1]+list(i)+[1],j) % primes[l]) is 0:
                         divisor[j-2] = (primes[l])
            else:
                flag = 0
                
        if flag == 1:
            count += 1
            result = (''.join(map(str,([1]+list(i)+[1]))) +  ' ' + ' '.join(map(str,divisor)))
            print(result)
            fOutput.write(result + '\n')
        
        if count >= J:
            break
    
    
    
    
fInput.close()
fOutput.close()
