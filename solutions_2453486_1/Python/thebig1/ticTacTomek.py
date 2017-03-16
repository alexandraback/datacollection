'''
Created on Apr 12, 2013

@author: user
'''

import sys

class Board:
    def __init__(self, values):
        ''' values is row major representation of the 4x4 board '''
        self.values = values
    
    def getRow(self, i):
        '''get the ith row'''
        return self.values[(4 * i):(4 * i + 4)]
    
    def getCol(self, i):
        '''get the ith column'''
        return self.values[i:(i + 13):4]
    
    def getDiag(self, l2R):
        if l2R:
            return self.values[0:16:5]
        else:
            return self.values[3:13:3]
    
    def wins(self, sequence):
        '''Return the winer of this length 4 sequence (row, col, or diagonal). If no winner,
        return false'''
        nX = sequence.count('X')
        nO = sequence.count('O')
        nT = sequence.count('T')
        
        if (nX == 4) or (nX == 3 and nT == 1):
            return 'X'
        elif (nO == 4) or (nO == 3 and nT == 1):
            return 'O'
        else:
            return False
    
    def getState(self):
        '''Return the state of the board. 'X', 'O', 'DRAW', or 'UNFINISHED''' 
        for i in range(4):
            iColWin = self.wins(self.getCol(i))
            if iColWin:
                return iColWin
            
            iRowWin = self.wins(self.getRow(i))
            if iRowWin:
                return iRowWin
            
        lRDiagWin = self.wins(self.getDiag(True))
        if lRDiagWin:
            return lRDiagWin
        
        rLDiagWin = self.wins(self.getDiag(False))
        if rLDiagWin:
            return rLDiagWin
        
        if '.' in self.values:
            return 'UNFINISHED'
        else:
            return 'DRAW'

def processFile(fileName):
    results = []
    
    with open(fileName) as handle:
        trials = int(handle.readline().strip())
        
        for i in range(trials):
            seq = []
            for j in range(4):
                seq += list(handle.readline().strip())
            board = Board(seq) 
            results.append(board.getState())
            handle.readline()
            
    return results
   
   
def writeResults(results, fileName):
    with open(fileName, 'w') as handle:
        
        case = 1
        
        for result in results:
            handle.write('Case #{}: '.format(case))
            
            if result == 'O':
                handle.write('O won')
            elif result == 'X':
                handle.write('X won')
            elif result == 'DRAW':
                handle.write('Draw')
            elif result == 'UNFINISHED':
                handle.write('Game has not completed')

            case += 1
            
            handle.write('\n')
            

def main():
    results = processFile(sys.argv[1])
    writeResults(results, sys.argv[2])

if __name__ == '__main__':
    main()