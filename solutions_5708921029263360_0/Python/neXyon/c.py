#!/usr/bin/python
# coding: utf-8
import sys
import numpy as np

def compute(J, P, S, K):
    result = np.zeros([J * P * S, 3], dtype=np.int64)
    
    result[:, 0] = np.tile(np.arange(J) + 1, P * S)
    result[:, 1] = np.tile(np.repeat(np.arange(P) + 1, J), S)
    result[:, 2] = np.repeat(np.arange(S) + 1, J * P)
    
    cumul_score = np.zeros((J * P * S, 3), dtype=np.int64)
    
    outfits = result
    
    result = []
    
    while len(outfits) > 0:
        ix = np.argmin(np.sum(cumul_score, axis=1))
        
        if np.max(cumul_score[ix, :]) == K:
            break
        
        outfit = outfits[ix, :].copy()
        result.append(outfit)
        
        cumul_score[ix:-1, :] = cumul_score[ix+1:, :]
        cumul_score = cumul_score[:-1, :]
        
        outfits[ix:-1, :] = outfits[ix+1:, :]
        outfits = outfits[:-1, :]
        
        cumul_score += np.transpose([np.sum(outfit[:2] == outfits[:, :2], axis=1) == 2,
                        np.sum(outfit[1:] == outfits[:, 1:], axis=1) == 2,
                        np.sum(outfit[::2] == outfits[:, ::2], axis=1) == 2])
    
    result = str(len(result)) + '\n' + '\n'.join([' '.join([str(x) for x in y]) for y in result])
    
    return result

input_file = sys.stdin
output_file = sys.stdout

count = int(input_file.readline())

for i in range(count):
    input_line = input_file.readline().strip()
    
    numbers = [int(x) for x in input_line.split(' ')]

    result = compute(*numbers)
    
    result = 'Case #{0}: {1}\n'.format(i + 1, result)
    
    output_file.write(result)

