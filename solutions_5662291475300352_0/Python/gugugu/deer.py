from __future__ import division

import os
import sys
name = 'C-small-1-attempt0'

def _solve(hikers):
    print(hikers)
    if len(hikers) == 1 and hikers[0][1] == 1:
        print('tu')
        return 0
    if len(hikers) == 1 and hikers[0][1]==2:
        pos_a = pos_b = hikers[0][0]
        speed_a = hikers[0][2]
        speed_b = hikers[0][2] + 1
    else: 
        pos_a = hikers[0][0]
        pos_b = hikers[1][0]
        speed_a = hikers[0][2]
        speed_b = hikers[1][2]
    if pos_a > pos_b:
        tmp = pos_a
        pos_a = pos_b
        pos_b = tmp
        tmp = speed_a
        speed_a = speed_b
        speed_b = tmp
    if speed_a > speed_b:
        time_to_complete = (360-pos_a)/360*speed_a
        time_to_meet = (360-pos_b+360)/360*speed_b
        #print(time_to_complete)
        #print(time_to_meet)
        good = (360-pos_a)*speed_a < (360-pos_b+360)*speed_b
    else:
        time_to_complete = (360-pos_b)/360*speed_b
        time_to_meet = (360-pos_a+360)/360*speed_a
        good = (360-pos_b)*speed_b < (360-pos_a+360)*speed_a
    return 0 if good else 1

def format(out):
    return out

def solve(*args, **kwargs):
    return format(_solve(*args, **kwargs))

#print(solve(((180,1,10000), (180, 1, 1))),1)
#print(solve(((180,1,2), (180, 1, 1))),0)
#print(solve(((180,1,3), (180, 1, 1))),1)
#print(solve(((180,1,2), (180, 1, 1))),0)
#print(solve(((180,1,4), (180, 1, 1))),1)
#sys.exit(0)

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    n = int(lines[curline].strip())
    curline+=1
    inp = ()
    for i in range(n):
        _inp = tuple(int(x) for x in lines[curline].split())
        inp+=(_inp,)
        curline +=1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(inp))))
    output.flush()
output.close()
    








