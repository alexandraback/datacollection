'''
Created on 12/05/13 
Code Jam 2013 1C A
@author: manolo
'''

import sys
ifile = sys.stdin
ofile = open('./a-small.out', 'w')

def r():
    return ifile.readline()[:-1]
    
def w(what):
    ofile.write(what + '\n')

vowels = ['a', 'e', 'i', 'o', 'u']
def consecutive_consonants(name, n):
    current_con = 0
    for char in name:
        if char in vowels:
            if current_con >= n:
                return 1
            current_con = 0
        else:
            current_con += 1
        
    if current_con >= n:
        return 1
    else:
        return 0
    

T = int(r())
for case in range(1,T+1):
    (name, N) = r().split(' ')
    n = int(N)
    
    res = 0
    for start in range(len(name)):
        for end in range(start, len(name)):
            res += consecutive_consonants(name[start:end+1], n)
            
        
    w('Case #' + str(case) + ': ' + str(res))


ofile.close

