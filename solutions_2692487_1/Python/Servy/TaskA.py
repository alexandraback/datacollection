'''
Created on 04.05.2013

@author: Servy
'''
import sys

def eat(a, motes):
    eaten = 0
    for m in motes:
        if a > m:
            a += m
            eaten += 1            
        else:
            break     
    return (a, motes[eaten:])           

def calcPromotes(a, b):
    res = 0
    
    if a - 1 == 0:
        return (a, 10000)
        
    while (a <= b):        
        a += a-1
        res += 1
    return (a, res)       

def solve(a, motes):
    (a, motes) = eat(a, motes)
    if len(motes) == 0:
        return 0
        
    (size, turns) = calcPromotes(a, motes[0])
    if turns < 1000:    
        way1 = solve(size, motes) + turns
        way2 = len(motes)
        return min(way1, way2)
    else:
        return len(motes)    

tests = int(sys.stdin.readline())

for t in range(tests):
    (a, n) = map(int, sys.stdin.readline().split())
    sizes =  list(map(int, sys.stdin.readline().split()))
    sizes.sort()
    result = solve(a, sizes)
    print("Case #%d: %d" % (t+1, result))
    
        
    