#!/usr/bin/python
import sys
import math



def boards(blanks,mines,clicks):
    if(blanks>0):
        for b in boards(blanks-1,mines,clicks):
           yield [' ']+b
    if(mines>0):
        for b in boards(blanks,mines-1,clicks):
           yield ['*']+b
    if(clicks>0):
        for b in boards(blanks,mines,clicks-1):
           yield ['c']+b
    if(blanks==0 and mines==0 and clicks==0):
        yield []

def prev(row):
    if(row==0):
        return 0
    return row-1

def nxt(row,rows):
    if(row+1==rows):
        return row
    return row+1

def doclick(board,rows,cols,click):
    row=click/cols
    col=click%cols
    count=0
    for xr in range(prev(row),nxt(row,rows)+1):
      for yr in range(prev(col),nxt(col,cols)+1):
        x=xr*cols+yr
        if(board[x]=='*'):
            count=count+1
    if(count==0):
      for xr in range(prev(row),nxt(row,rows)+1):
        for yr in range(prev(col),nxt(col,cols)+1):
          x=xr*cols+yr
          if(board[x]==' '):
              board[x]='.'
              doclick(board,rows,cols,x)
    
def oneclick(board,rows,cols):
    #print 'oneclick in:'
    #print form(board,rows,cols)
    click=board.index('c')
    doclick(board,rows,cols,click)
    #print 'oneclick out:'
    #print form(board,rows,cols)
    try:
        board.index(' ')
        return 0
    except ValueError:
        return 1

def form(board,rows,cols):
    ret="";
    for i in range(rows):
        for j in range(cols):
            ret+=str(board[i*cols+j])
        ret+='\n'
    return ret
    
def solve(r,c,m):
    for b in boards((r*c)-m-1,m,1):
        if oneclick(b,r,c):
           return(form(b,r,c))
    return "Impossible"

[cases]=map(int,sys.stdin.readline().split());
for caseid in range(cases):
    [r,c,m]=map(int,sys.stdin.readline().split());
    result=solve(r,c,m)
    print "Case #"+str(caseid+1)+":"
    print result
