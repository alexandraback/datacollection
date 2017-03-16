#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    S = list(raw_input().strip())
    alpha = {}
    for s in S:
        if s not in alpha:
            alpha[s] = 1
        else:
            alpha[s] += 1
    N = len(S)
    answer = []
    while N:
        if 'Z' in alpha: # ZERO
            c = alpha['Z']
            alpha['Z'] -= c
            alpha['E'] -= c
            alpha['R'] -= c
            alpha['O'] -= c
            N -= 4*c
            for _ in range(c):
                answer.append('0')
        
        if 'W' in alpha: # TWO
            c = alpha['W']
            alpha['T'] -= c
            alpha['W'] -= c
            alpha['O'] -= c
            N -= 3*c
            for _ in range(c):
                answer.append('2')

        if 'X' in alpha: # SIX
            c = alpha['X']
            alpha['S'] -= c
            alpha['I'] -= c
            alpha['X'] -= c
            N -= 3*c
            for _ in range(c):
                answer.append('6')
                
        if 'S' in alpha and alpha['S']: # SEVEN
            c = alpha['S']
            alpha['S'] -= c
            alpha['E'] -= 2*c
            alpha['V'] -= c
            alpha['N'] -= c
            N -= 5*c
            for _ in range(c):
                answer.append('7')

        if 'G' in alpha: # EIGHT
            c = alpha['G']
            alpha['E'] -= c
            alpha['I'] -= c
            alpha['G'] -= c
            alpha['H'] -= c
            alpha['T'] -= c
            N -= 5*c
            for _ in range(c):
                answer.append('8')
        
        if 'V' in alpha and alpha['V']: # FIVE
            c = alpha['V']
            alpha['F'] -= c
            alpha['I'] -= c
            alpha['V'] -= c
            alpha['E'] -= c
            N -= 4*c
            for _ in range(c):
                answer.append('5')
        
        if 'I' in alpha and alpha['I']: # NINE
            c = alpha['I']
            alpha['N'] -= 2*c
            alpha['I'] -= c
            alpha['E'] -= c
            N -= 4*c
            for _ in range(c):
                answer.append('9')
        
        if 'F' in alpha and alpha['F']: # FOUR
            c = alpha['F']
            alpha['F'] -= c
            alpha['O'] -= c
            alpha['U'] -= c
            alpha['R'] -= c
            N -= 4*c
            for _ in range(c):
                answer.append('4')
        
        if 'O' in alpha and alpha['O']: # ONE
            c = alpha['O']
            alpha['O'] -= c
            alpha['N'] -= c
            alpha['E'] -= c
            N -= 3*c
            for _ in range(c):
                answer.append('1')

        if 'H' in alpha and alpha['H']: # THREE
            c = alpha['H']
            alpha['T'] -= c
            alpha['H'] -= c
            alpha['R'] -= c
            alpha['E'] -= 2*c
            N -= 5*c
            for _ in range(c):
                answer.append('3')

    answer = "".join(sorted(answer))
    print "Case #%i: %s\n" % (t+1, answer)


