#!/usr/bin/python

def myprint(field,invert):
    #print repr(field)
    if invert:
        for c in range(len(field[0])):
            s=""
            for r in range(len(field)):
                s+= str(field[r][c])
            print s
    else:
        for r in range(len(field)):
            s=""
            for c in range(len(field[0])):
                s+= str(field[r][c])
            print s
            
def failprint():
    print "Impossible"
    

def solve(r,c,m,invert):
    field = []
    for i in range(r):
        field.append(["*"]*c)
    field[0][0] = "c"
    
    if r==1:
        for i in range(1,c-m):
            field[0][i] = "."
        myprint(field,invert)
        return
        
    total=r*c
    nonm=total-m
    
    if nonm == 1:
        myprint(field,invert)
        return
        
    if nonm in [2,3,5,7]:
        failprint()
        return 
        
    if r==2:
        if nonm%2==1:
            failprint()
            return
        else:
            field[1][0] = "."
            for i in range(1,nonm/2):
                field[0][i] = "."
                field[1][i] = "."
            myprint(field,invert)
            return
    
    if nonm <= 2*c +1:
        if nonm%2==1:
            field[2][0] = "."
            field[2][1] = "."
            field[2][2] = "."
            nonm-=3
        field[1][0] = "."
        for i in range(1,nonm/2):
            field[0][i] = "."
            field[1][i] = "."  
        
        myprint(field,invert)
        return
        
    field[1][0] = "."
    for i in range(1,c):
        field[0][i] = "."
        field[1][i] = "."  
    nonm -=2*c
    
    nextr = 2
    while True:
        if nonm==1:
            field[nextr][0] = "."
            field[nextr][1] = "."
            field[nextr-1][c-1] = "*"
            myprint(field,invert)
            return
            
        if nonm <= c:
            for i in range(0,nonm):
                field[nextr][i] = "."
            myprint(field,invert)
            return
            
        for i in range(0,c):
            field[nextr][i] = "."
        nonm -=c
        nextr+=1
	
	

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":")
    	
    (r,c,m) = raw_input().split()
    r,c,m = int(r),int(c),int(m)
	
    if r > c:
        solve(c,r,m,True)
    else:
        solve(r,c,m,False)
    
