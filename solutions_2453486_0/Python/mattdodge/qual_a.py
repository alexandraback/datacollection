'''
Created on Apr 12, 2013

@author: Matt Dodge
'''

inFile = open('A-small-attempt0.in','r+')
outFile = open('A-small-attempt0.out','w')

def output(st):
    if outFile == 'stdout':
        print st
    else:
        outFile.write(st)

# return True if the same (or if one is T)
def checkMatch(v1, v2):
    return v1 != '.' and v2 != '.' and (v1 == v2 or v1 == 'T' or v2 == 'T')

# return 'X' or 'O' or False if nothing
def checkValid(v1, v2, v3, v4):
    if (checkMatch(v1,v2) and checkMatch(v2,v3) and checkMatch(v3,v4) and checkMatch(v1,v3) and checkMatch(v1,v4) and checkMatch(v2,v4)):
        # all the same
        if v1 != 'T':
            return v1
        else:
            return v2
        
    return False

def checkBoard(l1, l2, l3, l4):
    # check horizontals
    for pos in range(0,4):
        winner = checkValid(l1[pos], l2[pos], l3[pos], l4[pos])
        if winner:
            return winner + ' won'
        
    # check verticals
    for pos in [l1,l2,l3,l4]:
        winner = checkValid(pos[0], pos[1], pos[2], pos[3])
        if winner:
            return winner + ' won'
        
    # check diagonals
    winner = checkValid(l1[0], l2[1], l3[2], l4[3])
    if winner:
        return winner + ' won'
    
    winner = checkValid(l4[0], l3[1], l2[2], l1[3])
    if winner:
        return winner + ' won'
    
    if '.' in l1 or '.' in l2 or '.' in l3 or '.' in l4:
        return 'Game has not completed'
    else:
        return 'Draw'

if __name__ == '__main__':
    numCases = int(inFile.readline().rstrip('\n'))
    
    for case in range(1, numCases+1):
        board = checkBoard(
                inFile.readline().rstrip('\n'),
                inFile.readline().rstrip('\n'),
                inFile.readline().rstrip('\n'),
                inFile.readline().rstrip('\n')   )
        
        inFile.readline()
        output('Case #{0}: {1}\n'.format(case, board))
    
