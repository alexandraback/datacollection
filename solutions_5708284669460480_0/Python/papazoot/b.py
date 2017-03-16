from Solve import *
from math import *
from itertools import product

def monkey(args):
    keyboardLen, targetLen, resultLen = [int(e) for e in args[0].split(" ")]
    keyboard = args[1]
    target = args[2]
    
    for c in target:
        if c not in keyboard:
            return 0.0
            
    total = 0
    repeats = []
    for c in product(keyboard, repeat = resultLen):
        cs = "".join(c)
        repeat = countString(cs, target)
        repeats.append(repeat)
        total+=1
  
    prob = 1.0 / total
    average = sum([prob * repeat for repeat in repeats])
    maxRepeats = max(repeats)
    return maxRepeats - average
    
def countString(haystack, needle):
    count = 0
    for i, _ in enumerate(haystack):
        if haystack[i:i + len(needle)] == needle:
            count+=1
    return count
         
solveF("F:\ProgramiranjeOstalo/GCJ/1c_2015/B-small-attempt0.in", monkey, 3)