import os
import math
import copy
import sys

os.chdir('C:/Python33/2014')
f = open('C-small-attempt0.in','r')
fo = open('C-small.out','w')
T = int(f.readline())
for ite in range(T):
    temp = str.split(f.readline())
    r0,c0,m0 = int(temp[0]),int(temp[1]),int(temp[2])
    temp = 0
    layer = 1
    p = [['.' for x in range(c0)] for y in range(r0)]
    while temp<m0:
        temp = temp+r0+c0-(2*layer-1)
        layer = layer+1
    layer = layer-1
    r = r0-layer+1
    c = c0-layer+1
    m = m0-(temp-(r+c-1))
    for i in range(layer-1):
        p[i] = ['*']*c0
        for j in range(r0):
            p[j][i] = '*'
    #print(r,c,m,layer)
    #for i in range(r0):
    #    for j in range(c0):
    #        fo.write(p[i][j])
    #    fo.write('\n')
    t = r+c-1
    fo.write('Case #')
    fo.write(str(ite+1))
    fo.write(': \n')
    if m0==(r0*c0-1):
        for i in range(r0):
            for j in range(c0):
                p[i][j] = '*'
        p[r0-1][c0-1] = 'c'
        for i in range(r0):
            for j in range(c0):
                fo.write(p[i][j])
            fo.write('\n')
    elif m0==0:
        for i in range(r0):
            for j in range(c0):
                p[i][j] = '.'
        p[r0-1][c0-1] = 'c'
        for i in range(r0):
            for j in range(c0):
                fo.write(p[i][j])
            fo.write('\n')
    elif m==t and r>2 and c>2:
        p[layer-1] = ['*']*c0
        for j in range(r0):
            p[j][layer-1] = '*'
        p[r0-1][c0-1] = 'c'
        for i in range(r0):
            for j in range(c0):
                fo.write(p[i][j])
            fo.write('\n')
    elif r==2 and c>2:
        if (r*c-m<4) or (m%2==1):
            fo.write('Impossible\n')
        else:
            for i in range(layer-1,layer-1+int(m/2)):
                p[r0-2][i] = '*'
                p[r0-1][i] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
    elif c==2:
        if (r*c-m==2) or (r*c-m==3) or (r*c-m==1) or (m%2==1):
            fo.write('Impossible\n')
        elif r*c-m==0:
            for i in range(r0):
                for j in range(c0):
                    p[i][j] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        else:
            for i in range(layer-1,layer-1+int(m/2)):
                p[i][c0-2] = '*'
                p[i][c0-1] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
    elif r==1:
        if r==r0:
            for i in range(layer-1,layer-1+m):
                p[r-1][i] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        else:
            if m==c-1:
                p[r0-1][c0-1] = 'c'
                for i in range(r0):
                    for j in range(c0):
                        fo.write(p[i][j])
                    fo.write('\n')
            else:
                fo.write('Impossible\n')
    elif c==1:
        if c==c0:
            for i in range(layer-1,layer-1+m):
                p[i][c-1] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        else:
            if m==r-1:
                p[r0-1][c0-1] = 'c'
                for i in range(r0):
                    for j in range(c0):
                        fo.write(p[i][j])
                    fo.write('\n')
            else:
                fo.write('Impossible\n')
    elif m<=t-4:
        if m<=r-2:
            for i in range(layer-1,layer-1+m):
                p[i][layer-1] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        else:
            for i in range(layer-1,layer-1+r-2):
                p[i][layer-1] = '*'
            for i in range(layer-1,layer-1+m-r+2+1):
                p[layer-1][i] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
    elif m==t-3:
        if m>=r:
            for i in range(layer-1,r0):
                p[i][layer-1] = '*'
            for i in range(layer-1,layer-1+c-3):
                p[layer-1][i] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        elif m>=c:
            for i in range(layer-1,c0):
                p[layer-1][i] = '*'
            for i in range(layer-1,layer-1+r-c):
                p[i][layer-1] = '*'
            p[r0-1][c0-1] = 'c'
            for i in range(r0):
                for j in range(c0):
                    fo.write(p[i][j])
                fo.write('\n')
        else:
            fo.write('Impossible\n')
    elif m == t-2:
        for i in range(layer-1,r0):
            p[i][layer-1] = '*'
        for i in range(layer-1,layer-1+c-2):
            p[layer-1][i] = '*'
        p[r0-1][c0-1] = 'c'
        for i in range(r0):
            for j in range(c0):
                fo.write(p[i][j])
            fo.write('\n')
    elif m == t-1:
        if r>=4 and c>=4:
            if r>=c:
                for i in range(layer-1,r0):
                    p[i][layer-1] = '*'
                for i in range(layer-1,layer-1+m-r):
                    p[i][layer] = '*'
                p[r0-1][c0-1] = 'c'
                for i in range(r0):
                    for j in range(c0):
                        fo.write(p[i][j])
                    fo.write('\n')
            else:
                for i in range(layer-1,c0):
                    p[layer-1][i] = '*'
                for i in range(layer-1,layer-1+m-c):
                    p[layer][i] = '*'
                p[r0-1][c0-1] = 'c'
                for i in range(r0):
                    for j in range(c0):
                        fo.write(p[i][j])
                    fo.write('\n')
        else:
            if r<5 and c<5:
                fo.write('Impossible\n')
            elif c>=5:
                if m%3==2:
                    fo.write('Impossible\n')
                elif m%3==0:
                    temp = int(m/3)
                    for i in range(layer-1,layer-1+3):
                        for j in range(layer-1,layer-1+temp):
                            p[i][j] = '*'
                    p[r0-1][c0-1] = 'c'
                    for i in range(r0):
                        for j in range(c0):
                            fo.write(p[i][j])
                        fo.write('\n')
                else:
                    temp = int(m/3)
                    for i in range(layer-1,layer-1+3):
                        for j in range(layer-1,layer-1+temp):
                            p[i][j] = '*'
                    p[layer-1][layer-1+temp] = '*'
                    p[r0-1][c0-1] = 'c'
                    for i in range(r0):
                        for j in range(c0):
                            fo.write(p[i][j])
                        fo.write('\n')
            else:
                if m%3==2:
                    fo.write('Impossible\n')
                elif m%3==0:
                    temp = int(m/3)
                    for i in range(layer-1,layer-1+temp):
                        for j in range(layer-1,layer-1+3):
                            p[i][j] = '*'
                    p[r0-1][c0-1] = 'c'
                    for i in range(r0):
                        for j in range(c0):
                            fo.write(p[i][j])
                        fo.write('\n')
                else:
                    temp = int(m/3)
                    for i in range(layer-1,layer-1+temp):
                        for j in range(layer-1,layer-1+3):
                            p[i][j] = '*'
                    p[layer-1+temp][layer-1] = '*'
                    p[r0-1][c0-1] = 'c'
                    for i in range(r0):
                        for j in range(c0):
                            fo.write(p[i][j])
                        fo.write('\n')
    else:
        print('else')
fo.close()

