import sys

def read(f):
    return f.readline()

def format(tup):
    return 'Case #%d: %s'%tup

def check(ary):
    x_cnt, o_cnt = 0, 0
    d_cnt, t_cnt = 0, 0 
    for i in ary:
        if i == 'X': x_cnt += 1 
        if i == 'O': o_cnt += 1 
        if i == 'T': t_cnt += 1
        if i == '.': d_cnt += 1
    if (x_cnt == 4) or (x_cnt == 3 and t_cnt == 1):
        return 'X'
    elif (o_cnt == 4) or (o_cnt == 3 and t_cnt == 1): 
        return 'O'
    elif d_cnt > 0:
        return 'D'
    else: 
        return 'N'

def judge(ary):
    exist_dot = False
    for i in xrange(4):
        row = ary[i]
        s = check(row)
        if s == 'X' : return 'X won' 
        if s == 'O' : return 'O won' 
        if s == 'D': exist_dot = True 
    for i in xrange(4):
        column = [ary[j][i] for j in xrange(4)]
        s = check(column)
        if s == 'X' : return 'X won' 
        if s == 'O' : return 'O won' 
    ldiag = [ary[i][i] for i in xrange(4)]
    s = check(ldiag)
    if s == 'X' : return 'X won' 
    if s == 'O' : return 'O won' 
    rdiag = [ary[i][3-i] for i in xrange(4)]
    s = check(rdiag)
    if s == 'X' : return 'X won' 
    if s == 'O' : return 'O won' 
    
    if exist_dot: return 'Game has not completed'  
    else: return 'Draw' 

f = open('A-large.in')
for i in range(int(read(f))):
    ary = [] 
    for _ in xrange(4):
        ary.append(list(read(f).split()[0]))
    read(f).split()
    print format((i+1,judge(ary)))
