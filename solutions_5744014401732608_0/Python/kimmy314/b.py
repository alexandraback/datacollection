# int(fInput.readline())
# fInput.readline().rstrip()
# [int(s) for s in str.split(fInput.readline().rstrip(),' ')]
# result = ' '.join(str(result[n]) for n in range(N))
import sys
import math
import numpy # http://www.numpy.org/
import string
import tkinter as tk
from tkinter.filedialog import askopenfilename

def debug(*args):
    print(" ".join(str(arg) for arg in args))
    return

root = tk.Tk()
root.withdraw()

filename = askopenfilename()
fInput = open(filename, 'r')
fOutput = open(filename.replace(".in", ".txt"), 'w+')

T = int(fInput.readline())

for t in range(T):
    info = [int(s) for s in str.split(fInput.readline().rstrip(),' ')]
    B = info[0]
    M = info[1]
    
    result = []
    
    numB = [1, 1]
    if B > 2:
        for i in range(2,B-1):
            numB.append(sum(numB))

    maxM = sum(numB)
    debug(maxM)

    if M > maxM:
        result = "IMPOSSIBLE"
        print('Case #{}: {}'.format(t+1, result))
        fOutput.write('Case #{}: {}\n'.format(t+1, result))
    else:
        result = "POSSIBLE"

        binString = M-1

        print('Case #{}: {}'.format(t+1, result))
        fOutput.write('Case #{}: {}\n'.format(t+1, result))

        print('{0:0{size}b}'.format(binString, size = B-1) + '1')
        fOutput.write('{0:0{size}b}'.format(binString, size = B-1) + '1' + '\n')
        
        for i in range(1,B-1):
            print('0'*(i+1) + '1'*(B-i-1))
            fOutput.write('0'*(i+1) + '1'*(B-i-1) + '\n')

        print('0'*B)
        fOutput.write('0'*B + '\n')
fInput.close()
fOutput.close()
