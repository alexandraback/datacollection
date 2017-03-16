#!/usr/bin/env python

import sys



def Solve(Lawn, N, M):
    LeftMax = [[0 for x in xrange(M)] for x in xrange(N)]
    RightMax = [[0 for x in xrange(M)] for x in xrange(N)]
    TopMax = [[0 for x in xrange(M)] for x in xrange(N)]
    DownMax = [[0 for x in xrange(M)] for x in xrange(N)]
    for i in range (N):
        for j in range (M):
            x = Lawn[i][j]
            if(j>0):
                LeftMax[i][j] = max(LeftMax[i][j-1], x)
            else:
                LeftMax[i][j] = x
            if(i>0):
                TopMax[i][j] = max(TopMax[i-1][j], x)
            else:
                TopMax[i][j] = x
    for i in range (N-1, -1, -1):
        for j in range (M-1, -1, -1):
            x = Lawn[i][j]
            if(j<M-1):
                RightMax[i][j] = max(RightMax[i][j+1], x)
            else:
                RightMax[i][j] = x
            if(i<N-1):
                DownMax[i][j] = max(DownMax[i+1][j], x)
            else:
                DownMax[i][j] = x
            if (x < TopMax[i][j] or x < DownMax[i][j]) and (x < LeftMax[i][j] or x < RightMax[i][j]): return False
    return True
                
 

def main():
    infile = open(sys.argv[1], 'r')
    inp = infile.readlines()
    T = int(inp[0])
    strn = 1
    for i in range(T):
        (N, M) = map(int, inp[strn].split())
        Lawn = [[0 for x in xrange(M)] for x in xrange(N)] 
        strn += 1
        for j in range(N):
            Lawn[j] = map(int, inp[strn].split())
            strn+=1
        if Solve(Lawn, N, M): print 'Case #'+str(i+1)+': YES'
        else: print "Case #"+str(i+1)+": NO"


if __name__=='__main__':
    main()
