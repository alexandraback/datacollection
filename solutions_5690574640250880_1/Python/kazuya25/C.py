import copy

# Obsolete
class Board(object):

    def __init__(self, lines):
        self.board = []
        i = 0
        click = [None, None]
        for line in lines:
            l = list(line.rstrip('\n'))
            j = 0
            for el in l:
                if el == "c":
                    click[0] = i
                    click[1] = j
                j += 1
            self.board.append(l)
            i += 1
        self.R = len(self.board)
        self.C = len(self.board[0])
        
        self.count(*click)
        for line in self.board:
            print line
        print self.verify()
        
    def count(self, k, l):
        r = [-1, 0 ,1]
        c = [-1, 0, 1]
        to_display = []
        count = 0
        for i in r:
            if k + i < 0 or k + i >= self.R:
                continue
            for j in c:
                if l + j < 0 or l + j >= self.C:
                    continue
                case = self.board[k+i][l+j]
                if case == '*':
                    count += 1
                if count == 0:
                    if case == ".":
                        to_display.append([k+i, l+j])
        
        if self.board[k][l] == 'c':
            pass
        else:
            self.board[k][l] = str(count)
        if count == 0:
            for couple in to_display:
                self.count(*couple)
        return count
    
    def verify(self):
        for i in range(self.R):
            for j in range(self.C):
                if self.board[i][j] == '.':
                    return False
        return True
class Case(object):
    solutions = {}
    def __init__(self, l):
        self.R = int(l[0])
        self.C = int(l[1])
        self.M = int(l[2])
        self.board = []
        line = ['.'] * self.C
        for i in range(self.R):
            self.board.append(copy.deepcopy(line))
            
        self.verified = False
    
    def __str__(self):
        s = ""
        for line in self.board:
            s += ''.join(line) + '\n'
        return s[:-1]
    @staticmethod
    def transpose(case):
        if case is None:
            return None
        c = Case( [case.C, case.R, case.M])
        for i in range(case.R):
            for j in range(case.C):
                c.board[j][i] = copy.deepcopy(case.board[i][j])
        
        return c
        
    @staticmethod
    def solve(case):
        #self.board[self.R - 1][self.C - 1] = 'c'
        m = case.M
        r = case.R
        c = case.C
        has_been_transposed = False
        # Convention
        if r > c:
            has_been_transposed = True
            case = Case.transpose(case)
            r = case.R
            c = case.C
        
        if (r, c, m) in Case.solutions.keys():
            case = copy.deepcopy(Case.solutions[(r, c, m)])
            if has_been_transposed:
                case = Case.transpose(case)
            return case 

               
        # division entiere pour remplir la colonne
        k = m / r
        l = 0
        if k > 0:
            while c >= r and k > 0:
                for i in range(r):
                    case.fill(i, l)
                    m -= 1
                l += 1
                k -= 1
                c -= 1
            if m > 0:
                if r == 0 or c == 0:
                    pass
                s_case = Case([r, c, m])
                smaller_case = Case.solve(s_case)
                if smaller_case is None:
                    return None
                for i in range(0, r):
                    for j in range(l, case.C):
                        case.board[i][j] = smaller_case.board[i][j-l]

        else:
            r1 = m % c # fill line
            r2 = m % r # fill column
            col = 0
            line = 0
            special = False
            if c - r1 == 1 and c - r2 == 1 and c>1 and r >1:
                special = True
            elif c - r1 == 1:
                # then we fill the col
                col = 1
            elif r - r2 == 1 :
                line = 1
            else:
                col = 1 # default
            if special:
                for p in range(m-1):
                    case.fill(p, 0)
                case.fill(0,1)
            else:
                for p in range(m):
                    case.fill(col * p, line * p)

        
        case.board[case.R - 1][case.C - 1] = 'c'
        if not case.verify():
            Case.solutions[(case.R, case.C, case.M)] = None
            case = None
        else:
            Case.solutions[(case.R, case.C, case.M)] = case
        
        if has_been_transposed:
            case = Case.transpose(case)
        
        return case 
    def count(self, u, v):
        r = [-1, 0 ,1]
        c = [-1, 0, 1]

        count = 0
        for i in r:
            if u + i < 0 or u + i >= self.R:
                continue
            for j in c:
                if v + j < 0 or v + j >= self.C:
                    continue
                case = self.board[u+i][v+j]
                if case == '*':
                    count += 1
        return count
    
    def verify(self):
        u = 0
#         return True
        # Go up from c
        while self.count( self.R -1 -u , self.C -1) == 0 and u <= self.R -1:
            u += 1
        u += 1
        if u <= self.R - 1 and self.board[self.R - 1 - u][self.C -1] == '.':
            return False
        l = 0
        # Go left from c
        while self.count( self.R - 1 , self.C - 1 -l ) == 0 and l <= self.C -1:
            l += 1
        l += 1
        if l <= self.C - 1 and self.board[self.R - 1][self.C - 1 - l] == '.' and l > 0:
            return False    

        return True            
        
    def fill(self, i, j):
        self.board[i][j] = '*'
        if self.R-1 - i < 2 and self.C - j < 2:
            return False
        return True
    
    #def verify


class GJ(object):
    def __init__(self, file_in = "input.txt", file_out = "output.txt"):
        self.solutions = []
        with open(file_in) as f:
            lines = f.readlines()
            self.T = int(lines[0])
            self.lines = lines[1:]
        self.process()
        self.output(file_out) 
           
    def process(self):
        for i in range(self.T):
            case = Case.solve(Case(self.lines[i].split()))
            if case is None:
                self.solutions.append("Impossible")
                print self.lines[i]
            else:
                self.solutions.append(str(case))
    
    
    def output(self, output):
        l = map(lambda x: "Case #%d:\n%s\n"%(int(x[0])+1, x[1]), enumerate(self.solutions))
        with open(output, "w") as f:
            f.writelines(l)
            

GJ()

## --------
## TEST
import random
print Case.solve(Case([5, 5, 4]))
#Board(str(Case.solve(Case([46, 24, 240]))).split('\n'))

# for u in range(250):
#     i = random.randint(1, 5)
#     j = random.randint(1, 5)
#     m = random.randint(0, i * j -1)
#     print i, j, m
#     print Case.solve(Case([i, j, m]))
    #Board(str(Case.solve(Case([i, j, m]))).split('\n'))
# for m in range(9):
#     i = 3
#     j = 3
#     print i, j, m
#     print Case.solve(Case([i, j, m]))
#      
# with open("debug.txt") as f:
#     lines = f.readlines()
#     Board(lines)