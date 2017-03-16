import sys
import math
import numpy # http://www.numpy.org/
import string
import tkinter as tk
from tkinter.filedialog import askopenfilename

root = tk.Tk()
root.withdraw()

def SplitNum(value):
    result = []
    for i in range(len(str(value))):
        result.append(int(str(value)[i]))
    return result

def NameSheep(value):
    result = value
    sheeps = list(range(11))
    prod = 1
    while len(sheeps)>1:
        numList = set(SplitNum(value*prod))
        #print(numList)
        sheeps = [x for x in sheeps if x not in numList]
            
        if len(sheeps) == 1:
            return value*prod
        
        prod += 1

        if prod > maxIter:
            return "INSOMNIA"

filename = askopenfilename()
fInput = open(filename, 'r')
fOutput = open(filename.replace(".in", ".txt"), 'w+')

cases = int(fInput.readline())
maxIter = 1E10
for i in range(cases):
    initial = int(fInput.readline())

    if initial == 0:
        result = "INSOMNIA"
    else:
        result = NameSheep(initial)
        
    fOutput.write("Case #{}: {}\n".format(i+1, result))
    print("Case #{}: {}".format(i+1, result))

    #print(SplitNum(initial))
    
fInput.close()
fOutput.close()
