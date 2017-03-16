#!/usr/bin/python3
# coding: utf-8

import sys
import numpy as np

def find_candidates(score1, score2):
    score1, score2 = score1.copy(), score2.copy()

    try:
        i1 = score1.index('?')
    except:
        i1 = len(score1)
        
    try:
        i2 = score2.index('?')
    except:
        i2 = len(score2)

    index = min(i1, i2)
    
    if index == len(score1):
        diff = np.abs(int(''.join(score1)) - int(''.join(score2)))
        
        return score1, score2, diff
    
    candidates = []

    if score1[index] == '?' and score2[index] == '?':
        score1[index], score2[index] = '0', '0'
        candidates.append(find_candidates(score1, score2))
        
        score1[index], score2[index] = '0', '1'
        candidates.append(find_candidates(score1, score2))

        score1[index], score2[index] = '0', '9'
        candidates.append(find_candidates(score1, score2))
        
        score1[index], score2[index] = '1', '0'
        candidates.append(find_candidates(score1, score2))

        score1[index], score2[index] = '9', '0'
        candidates.append(find_candidates(score1, score2))
        
        score1[index], score2[index] = '9', '9'
        candidates.append(find_candidates(score1, score2))
        
    elif score1[index] == '?':
        score1[index] = '0'
        candidates.append(find_candidates(score1, score2))
        
        if score2[index] != '0':
            score1[index] = str(int(score2[index]) - 1)
        candidates.append(find_candidates(score1, score2))
        
        score1[index] = score2[index]
        candidates.append(find_candidates(score1, score2))
        
        if score2[index] != '9':
            score1[index] = str(int(score2[index]) + 1)
        candidates.append(find_candidates(score1, score2))

        score1[index] = '9'
        candidates.append(find_candidates(score1, score2))
    else:
        score2[index] = '0'
        candidates.append(find_candidates(score1, score2))
        
        if score1[index] != '0':
            score2[index] = str(int(score1[index]) - 1)
        candidates.append(find_candidates(score1, score2))
        
        score2[index] = score1[index]
        candidates.append(find_candidates(score1, score2))
        
        if score1[index] != '9':
            score2[index] = str(int(score1[index]) + 1)
        candidates.append(find_candidates(score1, score2))

        score2[index] = '9'
        candidates.append(find_candidates(score1, score2))
    
    best = candidates[0]
    
    for candidate in candidates:
        if candidate[2] < best[2]:
            best = candidate
            
    return best

def compute(score1, score2):
    score1 = list(score1)
    score2 = list(score2)
    
    score1, score2, _ = find_candidates(score1, score2)
    
    output = ''.join(score1) + ' ' + ''.join(score2)
    
    return output


input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline()
    
    score1, score2 = [x.strip() for x in input_line.split(' ')]
    
    result = compute(score1, score2)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)
