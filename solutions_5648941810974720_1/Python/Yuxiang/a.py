import numpy as np

number = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
cha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def decrease(d, index, num):
    for c in number[index]:
        d[c] -= num

t = int(input())

for z in range(t):
    s = raw_input()
    d = {}
    for c in cha:
        d[c] = 0
    for c in s:
        d[c] += 1
    # 0268413579
    res = [0 for i in range(10)]
    
    res[0] = d['Z']
    decrease(d, 0, res[0])
        
    res[2] = d['W']
    decrease(d, 2, res[2])
    
    res[6] = d['X']
    decrease(d, 6, res[6])
    
    res[8] = d['G']
    decrease(d, 8, res[8])
    
    res[4] = d['U']
    decrease(d, 4, res[4])
    
    res[1] = d['O']
    decrease(d, 1, res[1])
    
    res[3] = d['H']
    decrease(d, 3, res[3])
    
    res[5] = d['F']
    decrease(d, 5, res[5])
    
    res[7] = d['V']
    decrease(d, 7, res[7])
    
    res[9] = d['I']
    decrease(d, 9, res[9])
    
    out = ""
    for i in range(10):
        out += str(i) * res[i]
    
    print "Case #{}: {}".format(z + 1, out)
    

