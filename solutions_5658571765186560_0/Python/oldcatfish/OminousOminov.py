# -*- coding: utf-8 -*-
'''
Small dataset

T = 64.
1 ≤ X, R, C ≤ 4.
Large dataset

1 ≤ T ≤ 100.
1 ≤ X, R, C ≤ 20.
'''

X = 3;
R = 2;
C = 3;

def player_b_win(x, r, c):
    if r > c:
        r, c = c , r;
    
    if (r*c)%x != 0:
        return(False);

    if x >= 7:
        return(False);
    if x == 1:
        return(True);
    
    if x == 2:
        return(True);
    if x == 3:
        if r == 1:
            return(False);
            
    if x == 4:
        if r == 1:
            return(False);
        if r == 2:
            return(False);
        
        if r == 3:
            return(True);
    if x == 5:
        if r == 1 or r == 2:
            return(False);
        if r == 3:
            return(False);
    if x == 6:
        if r == 1 or r == 2 or r == 3:
            return(False);
          
    
    return(True);
    
## read file and output            
infile = open('D-small-attempt0.in', 'r');
num_test = int(next(infile));

for indx_test in range(num_test):
    tmp = next(infile);
    tmp = tmp.split();
    x = int(tmp[0]);
    r = int(tmp[1]);
    c = int(tmp[2]);
    print('Case #' + str(indx_test + 1) + ': ', end="");
 
    if player_b_win(x, r, c):
        print('GABRIEL');
    else:
        print('RICHARD');          
        
        