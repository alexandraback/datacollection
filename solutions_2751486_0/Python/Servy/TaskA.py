'''
Created on 12.05.2013

@author: Servy
'''
import sys

tests = int(sys.stdin.readline())

def solve(name, n):
    res = 0
    last_known = -1
    count = 0    
    vowels = set(['a', 'e', 'i', 'o', 'u'])
    for i in range(len(name)):
        if not (name[i] in vowels):
            count += 1
            if (count >= n):
                last_known = i - n + 1
        else:
            count = 0
            
        if last_known >= 0:
            res += last_known + 1
    return res             
    

for t in range(tests):
    (name, n) = sys.stdin.readline().split()
    n = int(n)
    print("Case #%d: %d" % (t + 1, solve(name, n)))
    
    
    
    