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

for i in range(cases):
    info = fInput.readline().rstrip()

    position = 0
    result = 0
    if '-' not in info:
        result = 0
        
    else:
        while position < len(info):
            sign = info[position]
            
            while position < len(info) and info[position] == sign:
                position += 1

            result += 1
            
        if info[-1] == '+':
            result -= 1

            
    fOutput.write('Case #{}: {}\n'.format(i+1, result))
    print('Case #{}: {}'.format(i+1, result))
    
fInput.close()
fOutput.close()
