#!/usr/bin/python
# -*- coding: utf-8 -*-
import itertools

def concatenate(lists):
    return itertools.chain(*lists)
    
def main():
    in_file = open("B-small-attempt0.in", mode='r')
    out_file = open("B-small-attempt0.out", mode='w')

    lines = in_file.readlines()      
    T = int(lines[0])
    
    for i in xrange(T):
        line = lines[i + 1]
        C, J = line.split(' ')
        l = len(C)
        
        C_scores = [C]
        while '?' in list(concatenate(C_scores)):
            C_scores = list(concatenate(map(lambda s: [s.replace('?', str(i), 1) for i in range(10)] if '?' in s else [s], C_scores)))
        C_scores = map(lambda s: int(s), C_scores)
            
        J_scores = [J]
        while '?' in list(concatenate(J_scores)):
            J_scores = list(concatenate(map(lambda s: [s.replace('?', str(i), 1) for i in range(10)] if '?' in s else [s], J_scores)))
        J_scores = map(lambda s: int(s), J_scores)
            
        
        cs = C_scores[0]
        js = J_scores[0]
        for c, j in itertools.product(C_scores, J_scores):
            if abs(c-j) < abs(cs-js):
                cs, js = c, j
            elif abs(c-j) == abs(cs-js) and j < js:
                cs, js = c, j

        out_file.write("Case #" + str(i+1) + ": " + str(cs).zfill(l) + ' ' + str(js).zfill(l) + '\n') 
        
    in_file.close()
    out_file.close()


if __name__ == '__main__':
    main()
