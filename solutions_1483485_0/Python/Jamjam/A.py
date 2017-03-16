'''
Created on 14 apr. 2012

@author: Peter
'''
from sys import *

mapping = {'a' :'y'     ,
            'b' : 'h'   ,
            'c' : 'e'   ,
            'd' : 's'   ,
            'e' : 'o'   ,
            'f' : 'c'   ,
            'g' : 'v'   ,
            'h' : 'x'   ,
            'i' : 'd'   ,
            'j' : 'u'   ,
            'k' : 'i'   ,
            'l' : 'g'   ,
            'm' : 'l'   ,
            'n' : 'b'   ,
            'o' : 'k'   ,
            'p' : 'r'   ,
            'q' : 'z'   ,
            'r' : 't'   ,
            's' : 'n'   ,
            't' : 'w'   ,
            'u' : 'j'   ,
            'v' : 'p'   ,
            'w' : 'f'   ,
            'x' : 'm'   ,
            'y' : 'a'   ,
            'z' : 'q', ' ': ' '}

def solve(sentence):
    newsentence = ''
    for char in sentence:
        newsentence += mapping[char]
    return newsentence

cases = int(raw_input())
for case in xrange(1, cases + 1):
    sentence = stdin.readline().strip()
    print "Case #%s: %s" % (case, solve(sentence))
