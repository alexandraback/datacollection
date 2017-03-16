'''
Created on 12.05.2013

@author: Servy
'''
import sys

tests = int(sys.stdin.readline())

def getBestPath(value, startValue, _type):
    reversedCommands = False
    if value == 0:
        return ""    
    if value < 0:
        reversedCommands = True
    if not reversedCommands:
        up = ["E", "N"]
        down = ["W", "S"]
    else:
        up = ["W", "S"]
        down = ["E", "N"]
    
    value = abs(value)        
    
    res = ""
    curValue = 0
    i = startValue
    while curValue < value:
        curValue += i
        i += 1
        res += up[_type]
    
    other = curValue - (i-1)
    if abs(value - curValue) < abs(value - other):
        for i in range(curValue - value):
            res += up[_type] + down[_type]            
    else:
        res = res[:-1]
        for i in range(value - other):
            res += down[_type] + up[_type]
    return res    
                             

def solve(x, y):
    res1 = getBestPath(x, 1, 0)
    res1 += getBestPath(y, len(res1)+1, 1)
    
    res2 = getBestPath(y, 1, 1)
    res2 += getBestPath(x, len(res2)+1, 0)
    
    if len(res2) < len(res1):
        return res2    
    else:
        return res1

for t in range(tests):
    (x, y) = map(int, sys.stdin.readline().split())
    print("Case #%d: %s" % (t + 1, solve(x, y)))
    