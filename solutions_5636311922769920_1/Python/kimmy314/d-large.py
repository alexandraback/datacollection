import sys
import math
import numpy # http://www.numpy.org/
import string
import tkinter as tk
from tkinter.filedialog import askopenfilename

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
        if(value[-1-i] != 0):
            number += value[-1-i]*power
        power *= base
    return number

for i in range(cases):
    info = fInput.readline().rstrip()
    infoList = info.split(' ')

    K = int(infoList[0])
    C = int(infoList[1])
    S = int(infoList[2])

    if S < math.ceil(K/C):
        result = 'IMPOSSIBLE'
        fOutput.write('Case #{}: {}\n'.format(i+1, result))
        print('Case #{}: {}'.format(i+1, result))
    elif K == 1:
        result = 1
        fOutput.write('Case #{}: {}\n'.format(i+1, result))
        print('Case #{}: {}'.format(i+1, result))
    else:
        index = 0

        result = []
        for j in range(math.ceil(K/C)):
            inBase= []
            for k in range(C):
                inBase.append(index)
                index += 1
                if index >= K:
                    index = 0
           
            result.append(BaseConvert(inBase,K)+1)
        fOutput.write('Case #{}: {}\n'.format(i+1, ' '.join(map(str,result))))
        print('Case #{}: {}'.format(i+1, ' '.join(map(str,result))))
    
fInput.close()
fOutput.close()
