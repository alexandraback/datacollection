'''
Created on 10 apr. 2015

Standing Ovation

@author: Kristian
'''
import itertools
import sys
from random import randint

sys.setrecursionlimit(2 ** 20)

lines = [line.strip() for line in open('in.txt')]
out = open('./out.txt', 'w+')
cases = int(lines[0])

for case in range(1, cases+1):
    K,L,S = map(int, lines[case*3-2].split())
    keyboard = list(lines[case*3-1])
    target = list(lines[case*3])
    typed = []
    keyboard.sort()
    base_prob = 1.0/float(K)
    probs = {}
    
    for k in keyboard:
        if k in probs:
            probs[k] += base_prob
        else:
            probs[k] = base_prob
    
    running_prob = 0.0
    
    for s in target:
        if s not in probs:
            running_prob = 0.0
            break
        if running_prob == 0.0:
            running_prob = probs[s]
        else:
            running_prob *= probs[s]
    
    overlap = 0
    i=0
    j=len(target)-1
    while i <=j:
        if target[i] == target[j]:
            overlap += 1
        else:
            break
        i +=1
        j -=1
            
    
    bananas = (S-overlap)/L
    actual = bananas - running_prob*bananas
    
    
    out.write("Case #" + str(case) + ": " + str(round(actual,6)) + "\n")
out.close()