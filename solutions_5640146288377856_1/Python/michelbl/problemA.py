import os

os.chdir('/home/michel/workspace/googlecodejam/')
fi = open('A-large.in', 'r')
fo = open('A-large.out', 'w')


T = int(fi.readline())

for t in range(T):
    R, C, W = fi.readline().split(' ')
    R = int(R)
    C = int(C)
    W = int(W)
    sol = R*(((C-1)//W)+W)
    fo.write('Case #' + str(t+1) + ': ' + str(sol) + '\n')
    
fi.close()
fo.close()