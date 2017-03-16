'''
Created on 14.4.2012

@author: Antti
'''

tried = set()

def recycle(n):
    for i, c in enumerate(n):
        y = n[i:] + n[:i]
        if y[0]!='0':
            yield y

def recycle_set(n):
    return sorted(set([int(x) for x in recycle(n)]))

def num_recycled(n, A, B):
    rs = recycle_set(n)
    if rs[0] in tried:
        return 0
    le = len(rs)
    num = 0
    for i, x in enumerate(rs):
        for k in range(i+1,le):
            if x >= A and rs[k] <= B:
                num += 1
    tried.add(rs[0])
    return num

def calc(A,B):
    num = 0
    for i in range(A, B):
        num += num_recycled('%i'%i, A, B)
    return num

def solve(filename):
    global tried
    with file(filename) as f:
        cases = int(f.readline().strip())
        
        for i in range(cases):
            tried.clear()
            A, B = [int(p) for p in f.readline().split()]
            #A, B = f.readline().split()
            print 'Case #%i: %s' % (i+1, calc(A,B))
            
            
if __name__ == '__main__':
    solve('C-large.in')