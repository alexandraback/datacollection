'''
Created on Apr 26, 2013

@author: hwy
'''

def findMax(v):
    m = 0
    index = 0;
    for i in range(0, len(v)):
        if v[i] > m:
            m = v[i]
            index = i
    return [m, index]

def zero(v , t, R):
    if len(v) == 0: return 0
    [m, index] = findMax(v[0:t])
    en = m * R * (index + 1)
    return en + zero(v[index + 1:], t, R)  

def init():
    w = open('ou.txt', 'w')
    f = open('B-small-attempt0.in', 'r')
    num = int(f.readline())
    
    for i in range(1, num + 1):
        w.write('Case #' + str(i) + ': ')
        [E, R, N] = [long(s) for s in f.readline().split()]
        v = [long(s) for s in f.readline().split()]
        
        index = 0
        out = 0
        Et = E
        if R > E: R = E
        i = 0
        while i < len(v):
            if v[i] == max(v[i:]):
                out = out + Et * v[i]
                Et = R
                i = i + 1
                break
            else:
                out = out + R * v[i]
            i = i + 1
        
        t = long(E / R)
        out = out + zero(v[i:], t, R)
        w.write(str(out) + '\n')             
            
         
         
if __name__ == '__main__':
    init()
    
