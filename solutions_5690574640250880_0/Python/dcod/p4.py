import itertools
f = open('/Users/shivamahajan/Desktop/file.txt' , 'r')
ff = open('/Users/shivamahajan/Desktop/output.txt' , 'w')
import os


def getneighbours(a,b,r,c,minereal):
    result = 0
    for da in [-1,0,1]:
        for db in [-1,0,1]:
            newa = a+da
            newb = b+db
            if (da == 0 and db == 0):
                continue
            if (newa >= 0 and newa<r and newb >=0 and newb < c):
                result += minereal[newa][newb] 
    return result
        
def check(reach,minreal,a,b,r,c):
    reach[a][b] = 1
    #print a,b
    l = getneighbours(a,b,r,c,minereal)
    if l == 0:
        for da in [-1,0,1]:
            for db in [-1,0,1]:
                newa = a+da
                newb = b+db
                if (da == 0 and db == 0):
                    continue
                if (newa >= 0 and newa<r and newb >=0 and newb < c):
                    if(minereal[newa][newb] == 0 and reach[newa][newb] == 0):
                        check(reach , minereal , newa , newb , r , c) 


for q in xrange(int(f.readline().split()[0])):
    r,c,mn = [int(x) for x in f.readline().split()]
    ff.write("Case #" + str(q+1)+ ":" + os.linesep)
    minearray = []
    for i in xrange(r):
        for j in xrange(c):
            minearray.append([i,j])
    ok = 0
    #print minearray
    for j in (itertools.combinations(minearray,mn)):
        minereal = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
        for m in j:
            minereal[m[0]][m[1]] = 1
        for m in xrange(r*c):
            a = m/c
            b = m%c
            if minereal[a][b] == 0:
                reach  = [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
                check(reach , minereal , a , b , r , c)  
                #print reach
                summ= 0
                for g in reach:
                    summ += sum(g)
                if r*c-mn == summ:
                    for t in xrange(r):
                        s = ''
                        for tt in xrange(c):
                            if t == a and tt == b:
                                s += 'c'
                            elif minereal[t][tt]:
                                s += '*'
                            else:
                                s += '.'
                        ff.write(s + os.linesep)
                    ok = 1
                    break
        if ok:
            break
    if ok == 0:
        ff.write("Impossible" + os.linesep)
                            