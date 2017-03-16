#! /usr/bin/python

import string,sys

def judge_line(line):
    line = ''.join(line)
    if line.find('.')!=-1:
        return 'uncompleted'
    if line.find('X')==-1:
        return 'O won'
    if line.find('O')==-1:
        return 'X won'
    return 'this_line_completed'


def my_func(lines):
    
    ###### judge if x won
    state = 'Draw'
    for i in range(4):
        tmp = judge_line(lines[i])
        if tmp =='O won' or tmp == 'X won':
            return tmp
        if tmp == 'uncompleted':
            state = 'Game has not completed'

    for i in range(4):
        line = [lines[j][i] for j in range(4)]
        tmp = judge_line(line)
        if tmp =='O won' or tmp == 'X won':
            return tmp
        if tmp == 'uncompleted':
            state = 'Game has not completed'


    line = [lines[i][i] for i in range(4)]
    tmp = judge_line(line)
    if tmp =='O won' or tmp == 'X won':
        return tmp
    if tmp == 'uncompleted':
        state = 'Game has not completed'
    
    line = [lines[i][3-i] for i in range(4)]
    tmp = judge_line(line)
    if tmp =='O won' or tmp == 'X won':
        return tmp
    if tmp == 'uncompleted':
        state = 'Game has not completed'
    
    return state


if len(sys.argv)!=2:
    print 'argv!=2'
    sys.exit(1)

fin = open(sys.argv[1],'r')

sample_num = 0
line = fin.readline().strip()
sample_num = string.atoi(line)

for i in range(sample_num):
    tmp_input = []

    for k in range(4):
        tmp_input.append(fin.readline().strip())
        
    r = my_func(tmp_input)
    print "Case #%d: %s" %(i+1,r)
    fin.readline()
fin.close()
