'''
Created on Apr 9, 2016

@author: Linh
'''
import math
  
with open('c2.in') as f:
    lines = f.readlines()

with open('c2.out', 'w') as f:    
    T = int(lines[0])
    for i in xrange(1, T+1):
        N, J = [int(j) for j in lines[i].split()]
        f.write('Case #1:\n')
        
        for i in xrange(0, 2**(N-2)):
            jc = '1' + bin(i)[2:].zfill(N-2) + '1'
            res = []
            for base in xrange(2, 11):
                jcb = int(jc, base=base)
                for j in xrange(2, int(math.sqrt(jcb))+1):
                    if not (jcb % j):
                        res.append(str(j))
                        break
                else:
                    break
            else:
                f.write('%s %s\n' %(jc, ' '.join(res)))
                J -= 1
                if not J:
                    break