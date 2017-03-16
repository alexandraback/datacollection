# Tic Tac Toe Tomek: tictactoe

import re
import sys

def tictactoe(filename):
    def isway(field, i, j):
        v = field[i][j]
        for a in range(len(field)):
            if field[a][j] > v:
                break
        else:
            return True
        for a in range(len(field[0])):
            if field[i][a] > v:
                break
        else:
            return True
        return False
    def check(field):
        for i in range(len(field)):
            for j in range(len(field[0])):
                if not isway(field, i, j):
                    return False
        return True
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(total):
            dim = map(int, f_in.readline().strip().split(' '))
            field = []
            for j in range(dim[0]):
                row = map(int, f_in.readline().strip().split(' '))
                field.append(row)
            b = check(field)
            print 'Case #{0}: {1}'.format(i+1, 'YES' if b else 'NO')
            
if __name__ == "__main__":
    cs = sys.argv
    fun = globals()[cs[1]]
    fun(cs[2])
    
