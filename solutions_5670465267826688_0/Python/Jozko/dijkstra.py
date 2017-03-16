'''
Created on Apr 11, 2015

@author: jozefmokry
'''
import os

def read(path):
    with open(path, 'r') as f:
        T = f.readline().strip()
        T = int(T)
        outPath = os.path.splitext(path)[0] + 'OUT.txt'
        out = open(outPath, 'w')
        for i in range(T):
            line = f.readline().strip()
            L, X = line.split(' ')
            repeat = int(X)
            text = f.readline().strip()
            ans = solve(text, repeat)
            out.write('Case #%d: %s\n' % (i+1, ans))
        out.flush()
        out.close()
    print 'DONE'

MULT = {
        ('1', '1') : '1',
        ('1', 'i') : 'i',
        ('1', 'j') : 'j',
        ('1', 'k') : 'k',
        ('i', '1') : 'i',
        ('i', 'i') : '-1',
        ('i', 'j') : 'k',
        ('i', 'k') : '-j',
        ('j', '1') : 'j',
        ('j', 'i') : '-k',
        ('j', 'j') : '-1',
        ('j', 'k') : 'i',
        ('k', '1') : 'k',
        ('k', 'i') : 'j',
        ('k', 'j') : '-i',
        ('k', 'k') : '-1'
       }
  
def solve(text, repeat):
    text = text*repeat
    need = 'i'
    acc = '1'
    for c in text:
        acc = mult(acc, c)
        if acc == need:
            acc = '1'
            if need == 'i':
                need = 'j'
            elif need == 'j':
                need = 'k'
            elif need == 'k':
                need ='end'
    if need == 'end' and acc == '1':
        return 'YES'
    else:
        return 'NO'

def mult(a, b):
    aFactor, bFactor = 1, 1
    if a[0] == '-':
        aFactor = -1
        a = a[1:]
    if b[0] == '-':
        bFactor = -1
        b = b[1:]
    factor = aFactor*bFactor
    ans = MULT[(a,b)]
    if factor == 1:
        return ans
    elif ans[0] =='-':
        return ans[1:]
    else:
        return '-'+ans

read('C-small-attempt0.in')
        
    
    