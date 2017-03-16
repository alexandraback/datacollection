#!/usr/bin/python3


from sys import stdin

cases = int(stdin.readline())

for t in range(1, cases+1):
    line = stdin.readline().strip()
    [l, x] = line.split(' ', 1)
    l = int(l)
    x = int(x)
    
    line = stdin.readline().strip()
    answer = 'NO'
    if (l*x >= 3):
        wanted = 'i'
        m = '1' # previous
        n = None # new
        sign= 1
        pos = 0
        for ix in range(0, x):
            for il in range(0,l):
                c = line[il]
                if (m == c):
                    n = '1'
                    sign *= -1
                if (m == '1'):
                    n = c

                if (m == 'i') and (c == 'j'):
                    n = 'k'
                if (m == 'j') and (c == 'k'):
                    n = 'i'
                if (m == 'k') and (c == 'i'):
                    n = 'j'

                if (m == 'j') and (c == 'i'):
                    n = 'k'
                    sign *= -1
                if (m == 'k') and (c == 'j'):
                    n = 'i'
                    sign *= -1
                if (m == 'i') and (c == 'k'):
                    n = 'j'
                    sign *= -1
                m = n
                pos += 1

                if (sign == 1):
                    if (n == wanted):
                        if (n == 'i'):
                            wanted = 'j'
                            m = '1'
                        if (n == 'j'):
                            wanted = 'k'
                            m = '1'
                        if (n == 'k'):
                            if ((ix == (x-1)) and (il == (l-1))):
                                answer = 'YES'
    print (('Case #%d: %s' % (t,answer)))
