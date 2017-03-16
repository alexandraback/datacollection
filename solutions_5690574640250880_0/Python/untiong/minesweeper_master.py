import numpy as np

with open('C-small-attempt3.in', 'r') as dat, open('output.txt', '+w') as output:
    n = int(dat.readline())
    for h in range(n):
        t = False
        impossible = True
        r, c, m = list(map(int, dat.readline().strip('\n').split()))
        f = np.empty([r, c], dtype='S1')
        f[:] = "*"
        output.write('Case #' + str(h + 1) + ':\n')
        if r == 1 and c > m:
            f[0, :(c - m)] = '.'
            impossible = False
        
        elif c == 1 and r > m:
            f[:(r - m), 0] = '.'    
            impossible = False
        else:
            for i in range(r, 1, -1):
                g = 0
                for j in range(c, 1, -1):
                    temp = r*c - m - i*j
                    #print(i, j, temp)
                    if temp == 0 or temp > 1:
                        #print(i, j, temp)                        
                        if r - i >= c - j and r > i and temp <= j:   
                            f[i, :temp] = '.'
                            
                        elif c - j > r - i and c > j and temp <= i:
                            f[:temp, j] = '.'
                            
                        else:
                            continue
                        f[:i, :j] = '.'
                        impossible = False
                        g = 1
                        #print('test', i, j)
                        break
                if g:
                    break
        f[0, 0] = 'c'
        if r == c and m == r - 1 and c > 3:
            f = np.empty([r, c], dtype='S1')
            f[:] = "."
            for p in range(m):
                f[r - 1, 2:] = '*'
                f[r - 2 , c - 1] = '*'
            impossible = False
            f[0, 0] = 'c'
        if c > 1 and r > 1 and f[1, 0] == b'*' and f[0, 1] == b'*' and f[0, 1] == b'*' and f[1, 1] == b'*':
            impossible = True
        if r*c - m == 1: 
            impossible = False
        if m == 0:
            f = np.empty([r, c], dtype='S1')
            f[:] = "."
            f[0, 0] = 'c'
            impossible = False
            
        if impossible:
            output.write('Impossible\n')
            print('Case #' + str(h + 1) + ':', r, c, m,  r*c - m)
            print(f)

        else:

            for k in range(r):
                output.write(b''.join(f[k].tolist()).decode("utf-8") + '\n')
            
