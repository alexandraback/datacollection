sol = {False: 'RICHARD', True: 'GABRIEL' }

def solve(X, R, C):
    if X == 1: return True
    if X== 2: return (R % 2 == 0) or (C % 2 == 0)
    if X == 4: return (R == 4 and C >= 3) or (R >= 3 and C == 4)
    if X == 3: return (R == 3 and C >= 2) or (C == 3 and R >= 2) 
    
        


import sys
fin = sys.stdin
#fin = open('input.txt', 'r')
#fout = open('output.txt', 'w')

T = int(fin.readline().strip())
for t in range(T):
    X, R, C = map(int, fin.readline().split())
    res = sol[solve(X, R, C)]
    s = "Case #%d: %s\n" % (t+1, res)
    print s,



