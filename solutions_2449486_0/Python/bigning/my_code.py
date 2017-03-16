#! /usr/bin/python

import string,sys


def my_func(data,m,n):
    ressult = 'YES'
    state = [[0 for j in range(n)]for i in range(m)]
    for i in range(m):
        max_i = max(data[i])
        for j in range(n):
            if data[i][j]==max_i:
                state[i][j] = 1

    for j in range(n):
        t = [data[i][j] for i in range(m)]
        max_j = max(t)
        for i in range(m):
            if data[i][j] == max_j:
                state[i][j] =1
            
            if state[i][j] == 0:
                return 'NO'
    return 'YES'


if len(sys.argv)!=2:
    print 'sys.argv!=2'
    sys.exit(1)

fin = open(sys.argv[1])
sample_num =string.atoi(fin.readline().strip())

for i in range(sample_num):
    line = fin.readline().strip()
    fields = line.split(' ')
    m = string.atoi(fields[0])
    n = string.atoi(fields[1])
    
    tmp = []
    for k in range(m):
        line = fin.readline().strip()
        fields = line.split(' ')
        
        tt = []
        for j in range(n):
            tt.append(string.atof(fields[j]))
        
        tmp.append(tt)
    r = my_func(tmp,m,n)
    print 'Case #%d: %s' %(i+1,r)

fin.close()
