import math
import sys

def printMap2(r,c,m):
    resd=r*c-m
    if resd<4 and resd>1 and (r!=1 and c!=1):
        print "Impossible"
        return
    result=[]
    for i in xrange(r):
        result.append(['*']*c)
    row,col=0,0
    colLimit=int(min(c,max(math.ceil(math.sqrt(resd)),math.ceil(float(resd)/r))))
    for i in xrange(resd):
        #print r,c,row,col
        result[row][col] = '.'
        col+=1
        if col>=colLimit:
            col=0
            row+=1
    result[0][0]='c'
    if row==1 and col==colLimit-1 and resd!=1:
        print "Impossible"
        return
    if row>0 and col==1 and resd!=1:
        if row>2 and c>2:
            result[row][col] = '.'
            result[row-1][colLimit-1]='*'
            result[0][0]='c'
        else:
            print "Impossible"
            return
    for i in xrange(r):
        for j in xrange(c):
            sys.stdout.write(result[i][j])
        print

cases = int(raw_input())
for count in xrange(cases):
    r,c,m = map(int,raw_input().split())

    print "Case #%d:" % (count+1)
    printMap2(r,c,m)

