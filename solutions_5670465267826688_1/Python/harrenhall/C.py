#!/usr/bin/python
# print repr(st)
# maze = [[['#' for i in range(N+2)] for i in range(M+2)] for i in range(4)]
# (M, N) = map(int, f.readline().split())
# l = f.readline()


def qu(a,b):
    if a < 0:
        return -1 * qu(-1*a, b)
    if b < 0:
        return -1 * qu(a, -1*b)
        
    mul = [[0,0,0,0,0],
        [0,1,2,3,4],
        [0,2,-1,4,-3],
        [0,3,-4,-1,2],
        [0,4,3,-2,-1]]
        
    return mul[a][b]


def doit():
    (l,x) = raw_input().split()
    l = int(l)
    x = int(x)
    st = raw_input()
    ist = []
    for c in st:
        if c == "i":
            ist.append(2)
        elif c == "j":
            ist.append(3)
        elif c == "k":
            ist.append(4)
        else:
            print "errorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerrorerror"
    
    rounds = x
    if rounds > 60:
        rounds = 60
        
    val = 1
    search = 2
    for r in range(rounds):
        for i in range(l):
            val = qu(val,ist[i])
            if val == search:
                val = 1
                search+=1
    
    if search != 5:
        return "NO"
    
    vh = 1
    for i in range(l):
        vh = qu(vh,ist[i])
    
    rem = x - rounds
    while rem > 0:
        if rem % 2 == 1:
            val = qu(val,vh)
        rem /= 2
        vh = qu(vh,vh)
    if val == 1:
        return "YES"
    return "NO"
    
    
    

cases = input()
for case in range(1, cases+1):
    print ("Case #" + str(case) + ":"), doit()
