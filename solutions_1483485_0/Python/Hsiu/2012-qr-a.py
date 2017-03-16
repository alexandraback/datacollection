#! /usr/bin/python -tt

dic = {}
dic['a'] = 'Y'
dic['b'] = 'H'
dic['c'] = 'E'
dic['d'] = 'S'
dic['e'] = 'O'
dic['f'] = 'C'
dic['g'] = 'V'
dic['h'] = 'X'
dic['i'] = 'D'
dic['j'] = 'U'
dic['k'] = 'I'
dic['l'] = 'G'
dic['m'] = 'L'
dic['n'] = 'B'
dic['o'] = 'K'
dic['p'] = 'R'
dic['q'] = 'Z'
dic['r'] = 'T'
dic['s'] = 'N'
dic['t'] = 'W'
dic['u'] = 'J'
dic['v'] = 'P'
dic['w'] = 'F'
dic['x'] = 'M'
dic['y'] = 'A'
dic['z'] = 'Q' 

T = input()
f = open('out', 'w')
for Case in range(1, T+1):
    s = raw_input()
    for i in range(26):
        s = s.replace(chr(ord('a')+i), dic[chr(ord('a')+i)])
    s = s.lower()
    print s
    f.write('Case #%d: %s\n' % (Case, s))
