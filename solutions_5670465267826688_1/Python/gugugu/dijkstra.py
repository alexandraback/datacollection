
import os
import sys
name = 'C-large'

i='i'
j='j'
k='k'

qtable = {
    (1,1): (0, 1),
    (1,i): (0, i),
    (1,j): (0, j),
    (1,k): (0, k),
    (i,1): (0, i),
    (j,1): (0, j),
    (k,1): (0, k),
    (i,j): (0, k),
    (j,i): (1, k),
    (i,k): (1, j),
    (k,i): (0, j),
    (j,k): (0, i),
    (k,j): (1, i),
    (i,i): (1, 1),
    (j,j): (1, 1),
    (k,k): (1, 1),
}

def times(q1, q2):
    sign1, c1 = q1
    sign2, c2 = q2
    s, r = qtable[(c1, c2)]
    return ((s+sign1+sign2)%2, r)

def _solve(line, rep):
    goal = [(0,k), (0,j), (0,i)]

    acc = (0, 1)
    g = goal.pop()
    n = 0
    ii = 0
    while True:
        if ii >= rep:
            return False
        for ci, c in enumerate(line):
            acc = times(acc, (0, c))
            n += 1
            if n > 8*len(line):
                return False
            #print('acc g',acc, g)
            if acc == g:
                if goal:
                    g = goal.pop()
                    #print('goal', g, c, ci)
                    if not goal:
                        rep = min(rep, ii + 4 + (rep-ii) % 4)
                    n = 0
                    acc = (0,1)
                else:
                    if ii == rep - 1 and ci == len(line) - 1:
                        return True
        ii += 1
                    

def solve(line, rep):
    return 'YES' if _solve(line, rep) else 'NO'

#print(solve('ik', 1), 'NO')
#print(solve('ijk', 1), 'YES')
#print(solve('kji', 1), 'NO')
#print(solve('ji', 6), 'YES')
#print(solve('i', 10000), 'NO')
#
#print(solve('ji', 5), 'NO')
#print(solve('ji', 4), 'NO')
#print(solve('ji', 3), 'NO')
#print(solve('ji', 2), 'NO')
#sys.exit(0)

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    L,X = tuple(int(c) for c in lines[curline].split())
    #print(L,X)
    curline += 1
    line = lines[curline].strip()
    #print(line, len(line))
    curline += 1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(line, X))))
    output.flush()
output.close()
    








