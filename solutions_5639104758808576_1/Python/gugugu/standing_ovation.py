
import os
import sys
#name = 'A-small-practice'
name = 'A-large'

def solve(max_shy, shies):
    res = 0
    clapping = 0
    for i in range(0, max_shy+1):
        if clapping >= i:
            clapping += shies[i]
        else:
            new_friends = i - clapping
            res += new_friends
            clapping += shies[i] + new_friends
    return res



os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1

#print(solve(4, (1,1,1,1,1)), 0)
#print(solve(1, (0,9)), 1)
#print(solve(5, (1, 1, 0, 0, 1, 1)), 2)
#print(solve(0, (1,)), 0)
#sys.exit(0)

for caseno in range(cases):
    a = lines[curline]
    curline +=1
    max_shy, shies = tuple(a.split())
    shies = tuple(int(i) for i in tuple(shies))
    max_shy = int(max_shy)
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(max_shy, shies))))
output.close()

    








