from collections import Counter
import numpy as np

f = open('large.txt','r')
fo = open('out.txt','w')

T = int(f.readline())
t = 1

A = np.array([[1,0,0,0,0,0,0,0,0,0],
              [1,1,0,2,0,1,0,2,1,1],
              [1,0,0,1,1,0,0,0,0,0],
              [1,1,1,0,1,0,0,0,0,0],
              [0,1,0,0,0,0,0,1,0,2],
              [0,0,1,1,0,0,0,0,1,0],
              [0,0,1,0,0,0,0,0,0,0],
              [0,0,0,1,0,0,0,0,1,0],
              [0,0,0,0,1,1,0,0,0,0],
              [0,0,0,0,0,1,1,0,1,1],
              [0,0,0,0,0,1,0,1,0,0],
              [0,0,0,0,0,0,1,1,0,0],
              [0,0,0,0,0,0,1,0,0,0],
              [0,0,0,0,0,0,0,0,1,0]])
for t in range(1,T+1):
    freq = Counter()
    S = f.readline()
##    print(S)
    for c in S:
        freq[c] += 1

    letters = 'ZERONTWHFIVSXG'
    b = np.array([[freq[c]] for c in letters])
##    print(b)
    x = np.rint(np.linalg.lstsq(A,b)[0])
    number = []
    for i in range(10):
        ni = int(x[i][0])
        while ni>0:
            number.append(i)
            ni -= 1
##    print(number)
##    print(''.join(map(str,number)))
        
    
    fo.write('Case #{:d}: {:s}\n'.format(t,''.join(map(str,number))))
fo.close()
    
            
            
            

    
    
    
