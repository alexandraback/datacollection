'''
Created on 27.04.2013

@author: Servy
'''
import sys
import math

sys.stdin.readline()

(r, n, m, k) = map(int, sys.stdin.readline().split())

print("Case #1:")

def getDiv(n):
    r = n
    for i in range(2, n+1):
        if n % i == 0:            
            return i
        
def getAllDivs(n):
    r = []
    while n > 1:
        k = getDiv(n)
        r.append(k)
        n = n // k
    return r

def choose(number):
    bestDiff = 1
    bestNumber = -1
    for i in range(2, len(number)):
        diff = abs(number[i] - round(number[i]))
        if (diff < bestDiff) and (round(number[i]) > 0):
            bestDiff = diff
            bestNumber = i

    if bestNumber < 0:
        bestDiff = 1000        
        for i in range(2, len(number)):
            diff = abs(number[i] - 1)
            if diff < bestDiff:
                bestDiff = diff
                bestNumber = i
    
    number[bestNumber] -= 1
    return bestNumber      


for line in range(r):
    values = list(map(int, sys.stdin.readline().split()))
    divs = []
    for v in values:
        divs += getAllDivs(v)       
    
    
    prob = [0.0 for i in range(m+1)]
    number = [0.0 for i in range(m+1)]
    has = set()
    for v in values:
        if v in [2, 3, 5, 7]:
            has.add(v)
    
    for i in range(2, m+1):
        count = 0
        for d in divs:
            if i % d == 0:
                count += 1
        if len(divs) > 0:
            prob[i] = count / len(divs)
        else:
            prob[i] = 0
        if prob[i] > 0:
            number[i] = math.log(prob[i], 0.5)
        
    for i in range(2, m+1):
        for j in range(i+1, m+1):
            if j % i == 0:
                number[i] -= number[j]                
    
    s = ""
    for h in has:
        s += "%d" % (h)
        number[h] -= 1
    
    for i in range(n - len(s)):
        s += "%d" % (choose(number))
    print(s)   
        
                   
                  
    
        
    
    
                
    
    
    
    