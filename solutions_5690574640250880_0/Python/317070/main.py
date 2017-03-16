""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """

CLICK = 1
MINE = 2
EMPTY = 3
""" functions """
def primefactor(n):
    i = 2
    res = []
    while i * i <= n:
        while n%i == 0:
            n = int(n / i)
            res.append(i)
        i = i + 1
    if n!=1:
        res.append(n)
    return res

def rectangle(matrix, what, (top_left_r, top_left_c), (bottom_right_r, bottom_right_c) ):
    for i in xrange(top_left_r, bottom_right_r+1):
        for j in xrange(top_left_c, bottom_right_c+1):
            matrix[i][j] = what

def create(r,c,m):
    matrix = [[MINE for i in range(c)] for i in range(r)]
    '''matrix[r][c]'''
    
    e = (r*c)-m
    if (e > 12 and r>2 and c>2):
        #primes = primefactor(m)
        r1 = 3
        c1 = 3
        while r1*c1<e:
            if r1<r:
                r1+=1
            else:
                c1+=1
        
        if e%c1 in [1,]:
            for i in xrange(e+1):
                matrix[i/c1][i%c1] = EMPTY
            matrix[0][0]=CLICK
            matrix[r1-2][c1-1] = MINE
        else:
            for i in xrange(e):
                matrix[i/c1][i%c1] = EMPTY
            matrix[0][0]=CLICK
        return matrix
    else:
        #assert e<=12
        if e==1:
            matrix[0][0]=CLICK
            return matrix
        
        #assert r<=2 or c<=2 or 1<e<=12
        if r==1 or c==1:
            for i in xrange(e):
                matrix[i/c][i%c] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        
        if e==2 or e==3:
            return None
        #assert r>1 and c>1 and (r<=2 or c<=2 or 1<e<=12)
        if r==2 and c==2:
            if e==4:
                for i in xrange(e):
                    matrix[i/c][i%c] = EMPTY
                matrix[0][0]=CLICK
                return matrix
            else:
                return None
        
        #assert r>2 and c>2 and (r!=2 or c!=2) and (r<=2 or c<=2 or 1<e<=12)
        if c==2:
            return None
        if r==2:
            if e%2==1:
                return None
            else:
                for i in xrange(e):
                    matrix[i%r][i/r] = EMPTY
                matrix[0][0]=CLICK
                return matrix
        print e,r,c
        assert 1<e<=12 and r>2 and c>2
        
        if c==3 and r==3:
            if e==4:
                for i in xrange(e):
                    matrix[i/2][i%2] = EMPTY
                matrix[0][0]=CLICK
                return matrix
            elif e==6:
                for i in xrange(e):
                    matrix[i/3][i%3] = EMPTY
                matrix[0][0]=CLICK
                return matrix
            elif e==8:
                for i in xrange(e):
                    matrix[i/3][i%3] = EMPTY
                matrix[0][0]=CLICK
                return matrix
            elif e==9:
                for i in xrange(e):
                    matrix[i/3][i%3] = EMPTY
                matrix[0][0]=CLICK
                return matrix
            else:
                return None
        if c==3:
            return None
        
        assert 1<e<=12 and r>=3 and c>=4
        if e==4:
            for i in xrange(e):
                matrix[i/2][i%2] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        elif e==6:
            for i in xrange(e):
                matrix[i/3][i%3] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        elif e==8:
            for i in xrange(e):
                matrix[i/4][i%4] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        elif e==9:
            for i in xrange(e):
                matrix[i/3][i%3] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        elif e==10 or e==11 or e==12:
            for i in xrange(e):
                matrix[i/4][i%4] = EMPTY
            matrix[0][0]=CLICK
            return matrix
        else:
            return None
        
        return None
    

def solve(r,c,m):
    ''' ALWAYS LESS ROWS THAN COLUMNS!'''
    solution = create(r,c,m)
    if not solution:
        solution = create(c,r,m)
        if not solution:
            return "Impossible"
        #mirror
        solution = [[solution[i][j] for i in range(len(solution))] for j in range(len(solution[0]))]
    
    res = ""
    for i in xrange(len(solution)):
        for j in xrange(len(solution[0])):
            if solution[i][j]==MINE:
                res+= "*"
            elif solution[i][j]==EMPTY:
                res+="."
            elif solution[i][j]==CLICK:
                res+="c"
            else:
                raise
        if i!=len(solution)-1:
            res += "\n"
    assert res.count('*')==m
    assert res.count('c')==1
    assert res.count('.')==r*c-m-1
    return res

""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        ### calculate answer ###
        (r,c,m) = read_ints()
        answer = solve(r,c,m)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}:\n{}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)