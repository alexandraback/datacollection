import os
import sys
import random
from heapq import *
name = 'B-large'

def pop(heap):
    return - heappop(heap)

def peekmax(heap):
    return -heap[0]

def push(heap, elem):
    return heappush(heap, -elem)

def hpf(lst):
    res = [-v for v in lst]
    heapify(res)
    return res

def cann_ts(state, time, splits):
    state = list(state)
    if time < splits:
        return False
    a = (time - splits)
    if a<=0:
        return False
    while peekmax(state) > time - splits:
        mx = pop(state)
        b = mx - a
        push(state, a)
        push(state, b)
        splits -= 1
        time -= 1
        if splits < 0:
            return False
    return True
    
def can_t(plates, time):
    res = False
    splitss = list(range(0,1001))
    random.shuffle(splitss)
    state = hpf(plates)
    for splits in splitss:
        res = res or cann_ts(state, time, splits)
    return res

def solve(plates):
    mint = -1 
    maxt = 1001
    while True:
        midt = (mint+maxt) // 2
        if can_t(plates, midt):
            maxt = midt
        else:
            mint = midt
        if abs(mint-maxt)<=1:
            return maxt


#def solve(plates):
#    plates = sorted(plates)
#    res = 10**10
#    for time in range(0, 100):
#        for splits in range(0, 100):
#            state = [-v for v in plates]
#            heapify(state)
#            if cann(state, time, splits):
#                #if time < res:
#                #    print(time, splits)
#                res = min(res, time)
#    return res


#print(solve((3,)), 3)
#print(solve((1,2,1,2)), 2)
#print(solve((4,)), 3)
#print(solve((9,3,3)), 5)
#t = tuple(random.randint(1,1000) for _ in range(1000))
#for i in range(10):
#   print(solve(t))
#sys.exit(0)
        

os.system('cp /home/mama/Downloads/%s.in .'%name)
os.system('rm /home/mama/Downloads/%s*.in'%name)
lines = open('%s.in'%name).readlines()
output = open('%s.out'%name, 'w')
cases = int(lines[0])
curline = 1
for caseno in range(cases):
    n = int(lines[curline])
    curline += 1
    plates = tuple(int(k) for k in tuple(lines[curline].split()))
    curline += 1
    output.write('Case #%d: %s\n'%((caseno+1), str(solve(plates))))
output.close()
    








