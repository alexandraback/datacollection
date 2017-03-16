'''
Created on Apr 11, 2015

@author: jozefmokry
'''
import os, time

def read(path):
    date = time.strftime('%d_%h_%H_%M_%S')
    print date
    with open(path, 'r') as f:
        T = f.readline().strip()
        T = int(T)
        
        outPath = os.path.splitext(path)[0] + 'OUT_trial.txt'
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
    print time.strftime('%d_%h_%H_%M_%S')
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
    need = 'i'
    acc = '1'
    longText = text*min(repeat, 100)

    for c in longText:
        acc = mult(acc, c)
        if acc == need:
            acc = '1'
            if need == 'i':
                need = 'j'
            elif need == 'j':
                need = 'k'
            elif need == 'k':
                need ='end'
    if need != 'end':
        return 'NO'
    if repeat <= 100:
        #old case
        if acc == '1':
            return 'YES'
        else:
            return 'NO'
    else:
        #new case
        print 'new case'
        extra = repeat - 100
        total = '1'
        for c in text:
            total = mult(total, c)
        ending = mult(acc, pow(total, extra))
        if ending == '1':
            return 'YES'
        else:
            return 'NO'

        


def pow(a, n):
    if a == '1':
        return '1'
    if n % 4 == 0:
        return '1'
    if n % 4 == 1:
        return a
    if n % 4 == 2:
        return mult(a,a)
    if n % 4 == 3:
        return mult(a, mult(a, a))
    

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

read('C-large.in')
        
    
    