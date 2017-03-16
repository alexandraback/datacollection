import sys

class Puzzle(object):
    data = []
    allX = 0
    allXT = 0
    allO = 0
    allOT = 0
    def __init__(self, inputStream):
        self.data = [inputStream.readline()[:-1] for i in range(4)]
        self.allX = ord('X') * 4
        self.allXT = ord('X') * 3 + ord('T')
        self.allO = ord('O') * 4
        self.allOT = ord('O') * 3 + ord('T')

    def checkMark(self, mark):
        if mark == self.allX or mark == self.allXT:
            return 'X', False
        if mark == self.allO or mark == self.allOT:
            return 'O', False
        if mark < self.allO:             # min(allX, allXT, allO, allOT) == allO
            return None, True
        return None, False

    def checkRow(self, i):
        return self.checkMark(sum(map(ord, self.data[i])))

    def checkCol(self, i):
        return self.checkMark(sum(map(ord, [self.data[j][i] for j in range(4)])))

    def checkCros(self, i):     # i = 1 for \, -1 for /
        if i == 1:
            return self.checkMark(sum(map(ord, [self.data[j][j] for j in range(4)])))
        if i == -1:
            return self.checkMark(sum(map(ord, [self.data[j][-1 - j] for j in range(4)])))

    def checkWin(self):
        unfinished = False
        for i in range(4):
            win, dot = self.checkRow(i)
            if win != None:
                return win, None
            unfinished = unfinished or dot
        for i in range(4):
            win, dot = self.checkCol(i)
            if win != None:
                return win, None
            unfinished = unfinished or dot
        for i in [-1, 1]:
            win, dot = self.checkCros(i)
            if win != None:
                return win, None
            unfinished = unfinished or dot
        return None, unfinished

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        puzzle = Puzzle(sys.stdin)
        win, unfinished = puzzle.checkWin()
        if win != None:
            sys.stdout.write('{} won\n'.format(win))
        elif unfinished == True:
            sys.stdout.write('Game has not completed\n')
        else:
            sys.stdout.write('Draw\n')
        sys.stdin.readline()

