f_small = ['C-small-attempt6.in', 'small.out']
f_large = ['C-large.in', 'large.out']

#FILE_NAME = f_small
FILE_NAME = f_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

import math

l = []

def l_to_string(R, C, transe, l) :
    res = '\n'
    for i in range(R) :
        for j in range(C) :
            if transe == False :
                res += l[i][j]
            else :
                res += l[j][i]
        res += '\n'
        
    return res[:-1]

def case_result(case) :
    l.clear()
    R, C, M = [int(i) for i in f.readline().split(' ')]
    m = R*C - M
    if R > C :
        x = C
        y = R
        transe = True
        for i in range(C) : l.append([i for i in ('* '*R).split(' ')])

    else :
        x = R
        y = C
        transe = False
        for i in range(R) : l.append([i for i in ('* '*C).split(' ')])


    if m == 0 :
        return "\nImpossible"
    elif m == 1 :
        l[0][0] = 'c'
    elif x == 1 :
        for i in range(m) :
            l[0][i] = '.'
        l[0][0] = 'c'
    elif x == 2 :
        if m < 4 : return "\nImpossible"
        if m % 2 == 1 :
            return "\nImpossible"
        else :
            for i in range(int(m/2)) :
                l[0][i] = '.'
                l[1][i] = '.'
            l[0][0] = 'c'
            
    elif m < 4 or m == 5:
        return "\nImpossible"
    elif m == 4 :
        l[0][0] = 'c'
        l[0][1] = '.'
        l[1][0] = '.'
        l[1][1] = '.'        
    elif m == 6 :
        for i in range(3) :
            l[i][0] = '.'
            l[i][1] = '.'
        l[0][0] = 'c'
    elif m == 7 :
        return "\nImpossible"
    elif m == 8 :
        for i in range(3) :
            l[i][0] = '.'
            l[i][1] = '.'
            l[i][2] = '.'
        l[0][0] = 'c'
        l[2][2] = '*'
    elif m == 9 :
        for i in range(3) :
            l[i][0] = '.'
            l[i][1] = '.'
            l[i][2] = '.'
        l[0][0] = 'c'
    elif x == 3 :
        for i in range(int(m / 3)) :
            l[0][i] = '.'
            l[1][i] = '.'
            l[2][i] = '.'
        if m % 3 == 1 :
            l[0][int(m/3)] = '.'
            l[1][int(m/3)] = '.'
            l[2][int(m/3)-1] = '*'
        elif m % 3 == 2:
            l[0][int(m/3)] = '.'
            l[1][int(m/3)] = '.'
        l[0][0] = 'c'

    elif x < 6 or m >= 2*x:
        for i in range(int(m/x)) :
            for j in range(x) :
                l[j][i] = '.'
        for i in range(m % x) :
            l[i][int(m/x)] = '.'
        if m % x == 1 :
            l[1][int(m/x)] = '.'
            l[x-1][int(m/x)-1] = '*'
            if int(m/x) == 2 :
                l[x-1][0] = '*'
                l[2][int(m/x)] = '.'
        l[0][0] = 'c'
    else :
        for i in range(int(m/2)) :
            l[i][0] = '.'
            l[i][1] = '.'
        if m % 2 == 1 :
            l[int(m/2)-1][0] = '*'
            l[int(m/2)-1][1] = '*'
            l[0][2] = '.'
            l[1][2] = '.'
            l[2][2] = '.'

            
        l[0][0] = 'c'
        
    res = l_to_string(R, C, transe, l)
    return res
            
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
