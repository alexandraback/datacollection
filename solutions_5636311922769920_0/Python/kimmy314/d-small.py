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
    infoList = info.split(' ')

    K = int(infoList[0])
    C = int(infoList[1])
    S = int(infoList[1])
    ans = []
    for j in range(K):
        ans.append(j+1)

    fOutput.write('Case #{}: {}\n'.format(i+1, ' '.join(map(str,ans))))
    print('Case #{}: {}'.format(i+1, ' '.join(map(str,ans))))
    
fInput.close()
fOutput.close()
