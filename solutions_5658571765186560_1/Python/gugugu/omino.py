
import os
import sys
name = 'D-large'

def _solve(X, R, C):
    res = True
    res = res and ((R*C) % X == 0)
    for i in range(1, X):
        j = (1 + X - i)
        res = res and (min(i,j) <= min(R, C)) and (max(i,j) <= max(R, C))
        res = res and not(min(i,j) == min(R,C) and X>3)
    res = res and (X<7)
    return res

def solve(X, R, C):
    return "RICHARD" if not _solve(X, R, C) else "GABRIEL"

print(solve(2, 2, 2),'G')
print(solve(2, 1, 3),'R')
print(solve(4, 4, 1),'R')
print(solve(3, 2, 3),'G')
print(solve(3, 2, 3),'G')
#sys.exit(0)

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    args = tuple(int(v) for v in lines[curline].split())
    curline += 1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(*args))))
    print(args, _solve(*args))
    output.flush()
output.close()
    








