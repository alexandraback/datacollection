
import sys

from math import sqrt, ceil

def replaceRound1(s):
    a = s
    if 'Z' in s:        
        return ('0', a)
    if 'W' in s:
        for x in 'TWO':        
            a = a.replace(x, '', 1)
        return ('2', a)
    if 'U' in s:
        for x in 'FOUR':        
            a = a.replace(x, '', 1)
        return ('4', a)
    if 'X' in s:
        for x in 'SIX':        
            a = a.replace(x, '', 1)
        return ('6', a)
    if 'G' in s:
        for x in 'EIGHT':        
            a = a.replace(x, '', 1)
        return ('8', a)
    return None
        
def solve(s):
    a = s
    n = ''
    while 'Z' in a:
        for x in 'ZERO':        
            a = a.replace(x, '', 1)
        n += '0'
    while 'W' in a:
        for x in 'TWO':        
            a = a.replace(x, '', 1)
        n += '2'
    while 'U' in a:
        for x in 'FOUR':        
            a = a.replace(x, '', 1)
        n += '4'
    while 'X' in a:
        for x in 'SIX':        
            a = a.replace(x, '', 1)
        n += '6'
    while 'G' in a:
        for x in 'EIGHT':        
            a = a.replace(x, '', 1)
        n += '8'
    while 'H' in a:
        for x in 'THREE':        
            a = a.replace(x, '', 1)
        n += '3'
    while 'S' in a:
        for x in 'SEVEN':        
            a = a.replace(x, '', 1)
        n += '7'
    while 'F' in a:
        for x in 'FIVE':        
            a = a.replace(x, '', 1)
        n += '5'
    while 'O' in a:
        for x in 'ONE':        
            a = a.replace(x, '', 1)
        n += '1'
    while 'N' in a:
        for x in 'NINE':        
            a = a.replace(x, '', 1)
        n += '9'

    return ''.join(sorted(n))
    

def main():
    to_write = ''
    with open(sys.argv[1], 'r') as f:
        first_line = f.readline()
        count = 0
        
        for l in f:
            count += 1
            args = l.strip().split(' ')
            s = solve(args[0])
            to_write += 'Case #' + str(count) + ': ' + s + '\n'
    
    with open(sys.argv[2], 'w') as f:
        f.write(to_write)
        
if __name__ == '__main__':
    #print checkAllDivs('111111')
    #print checkAllDivs()
    #print getTest(15, 60)
    main()