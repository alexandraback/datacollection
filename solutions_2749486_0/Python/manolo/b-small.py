'''
Created on 12/05/2013
Code Jam 2013 1C - B
@author: manolo
'''

import sys
ifile = sys.stdin
ofile = open('./b-small.out', 'w')

def r():
    return ifile.readline()[:-1]
    
def w(what):
    ofile.write(what + '\n')

def get_to(x0, y0, x, y, incr, last_jump, jumps, d):

    if (x0, y0) == (x, y):
        return (True, jumps)
        
        
    # north (increasing y)
    if y0 < y:
    
        if last_jump == 'N':
            curr_incr = incr + 1
        else:
            curr_incr = 1
        
        (find, jumps) = get_to(x0, y0+curr_incr, x, y, curr_incr, 'N', jumps+'N', d+1)
        
        if find:
            return (find, jumps)

    
    # south (decreasing y)
    if y0 > y:
    
        if last_jump == 'S':
            curr_incr = incr + 1
        else:
            curr_incr = 1

        (find, jumps) = get_to(x0, y0-curr_incr, x, y, curr_incr, 'S', jumps+'S', d+1)
    
        if find:
            return (find, jumps)
    
    
    # east (increasing x)
    if x0 < x:
      
        if last_jump == 'E':
            curr_incr = incr + 1
        else:
            curr_incr = 1
      
        (find, jumps) = get_to(x0+curr_incr, y0, x, y, curr_incr, 'E', jumps+'E', d+1)
      
        if find:
            return (find, jumps)
    
    
    # west (decreasing x)
    if x0 > x:
      
        if last_jump == 'W':
            curr_incr = incr + 1
        else:
            curr_incr = 1
      
        (find, jumps) = get_to(x0-curr_incr, y0, x, y, curr_incr, 'W', jumps+'W', d+1)
      
        if find:
            return (find, jumps)


    return (find, jumps)

T = int(r())
for case in range(1,T+1):
    (x, y) = [int(c) for c in r().split(' ')]
    
    (find, jumps) = get_to(0, 0, x, y, 0, '', '', 0)
    
    
    w('Case #' + str(case) + ': ' + str(jumps))



ofile.close

