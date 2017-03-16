#!/usr/bin/python

import sys, math

T = sys.stdin.readline()

def threeplus(sp, m, r, c):
    matrix = []
    # print matrix
    for i in range(0,sp/c):
        matrix.append( ['.' for i in range(c)] )
    # print matrix
    if sp % c != 0:
        inter = ['.' for i in range(sp%c)]
        inter.extend(['*' for i in range(c - sp%c)])
        matrix.append( inter )
    # print matrix
    for i in range(0,m/c):
        matrix.append( ['*' for i in range(c)] )       
    # print matrix
    if sp%c == 1:
        #Move BAD mine
        matrix[sp/c][1] = '.'
        matrix[sp/c-1][c-1] = '*'               
    # print matrix
    return matrix
    
def delta0(r, c, dh, dv):
    matrix = [['.' for i in range(dh)]]
    matrix[0].extend(['*' for i in range(c-dh)])
    for i in range(1,dv):
        matrix.append(matrix[0][:])
    for i in range(0,r-dv):
        matrix.append(['*' for i in range(c)])
    
    return matrix

def delta(r, c, dc, dr, dd, RR):
    matrix = delta0(r, c, dc, dr)
    
    if dd == 1:
        # We need to move mine
        if (RR and (dr < 3)) or (not RR and (dc<3)):
            return None
        else:
            if RR:
                matrix[0][dc] = '.'
                matrix[1][dc] = '.'
                matrix[dr-1][dc-1] = '*'             
            else:
                matrix[dr][0] = '.'
                matrix[dr][1] = '.'
                matrix[dr-1][dc-1] = '*'
    else: 
        for t in range(dd):
            if RR:
                matrix[t][dc] = '.'
            else:
                matrix[dr][t] = '.'                
    
    return matrix



counter = 1
for line in sys.stdin:
    print 'Case #' + str(counter) + ':'
    counter += 1
    
    (r, c, m) = map(int, line.strip().split())
    
    # print r, c, m
    
    matrix = []
    sp = r*c-m
    
    if m == r*c:
        print 'Impossible'
    
    elif r==1:
        matrix = ['.' for i in range(r*c-m)]
        matrix.extend( ['*' for i in range(m)] )
        
        matrix = [matrix]
        
    elif c==1:
        matrix = ['.' for i in range(r*c-m)]
        matrix.extend( ['*' for i in range(m)] )
        
        matrix = [matrix]   
        matrix = map(list, zip(*matrix))
        
    elif m == (r*c-1):
        print 'c' + '*'*(c-1)
        for i in range(1,r):
            print '*'*(c)
        continue
            
    elif m > (r*c-4) or sp==5 or sp==7 or (r==2 and m%2==1) or (c==2 and m%2==1):
        print 'Impossible'
        continue
        
    elif sp/c > 2:        
        matrix = threeplus(sp, m, r, c)    
        
    elif sp/r > 2:
        matrix = threeplus(sp, m, c, r)        
        matrix = map(list, zip(*matrix)) 

    # elif c == 2:
    #     matrix = [['.', '.'] for i in range(sp/2)]
    #     matrix.extend([['*', '*'] for i in range(r-sp/2)])
    #             
    # elif r == 2:
    #     matrix = [['.', '.'] for i in range(sp/2)]
    #     matrix.extend([['*', '*'] for i in range(r-sp/2)])
    #     matrix = zip(*matrix)
        
    else:
        dh = int(round(math.sqrt(sp)))        
        dv = sp / dh
        
        dmin = min(dh,dv)
        dmax = max(dh,dv)
        
        dd = sp % dh

        if dd == 0:
            if dmin <= c and dmax <= r:
                matrix = delta0(r,c,dmin,dmax)
            elif dmin <= r and dmax <= c:
                matrix = delta0(r,c,dmax,dmin)
            else:
                dmin = min(r, c)
                dmax = sp/dmin
                dd = sp % dmin
                RR = True if r < c else False
                if RR:
                    matrix = delta(r,c,dmin, dmax, dd, RR)
                else:
                    matrix = delta(r,c,dmax, dmin, dd, RR)                                        
        else:
            # print dmin, dmax, dd
            if dmin+1 <= c and dmax <= r:
                matrix = delta(r,c,dmin,dmax,dd,True)                    
            elif dmax <= c and dmin+1 <= r:
                matrix = delta(r,c,dmax,dmin,dd,False)                    
            else:
                dmin = min(r, c)
                dmax = sp/dmin
                dd = sp % dmin
                RR = True if r < c else False
                if RR:
                    matrix = delta(r,c,dmin, dmax, dd, RR)
                else:
                    matrix = delta(r,c,dmax, dmin, dd, RR)                                                            

    # print matrix
    if matrix == None:
        print 'Impossible'
        continue
        
    matrix[0][0] = 'c'
    for item in matrix:
        print ''.join(item)







