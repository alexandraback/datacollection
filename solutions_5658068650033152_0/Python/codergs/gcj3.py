#! /opt/local/bin/python
from numpy import *
from itertools import *
import sys
sys.setrecursionlimit(10000)
#from gmpy2 import *
#f=open('test3')
f=open('C-small-attempt0.in')
#f=open('A-large.in')
T=int(f.readline())
for tt in range(1,T+1):
    [N,M,K]=[int(x) for x in f.readline().split()]
    dist = zeros([N,M])
    cross = zeros([N,M])
    Box= zeros([N,M])
    for i in range(N):
        for j in range(M):
            dist[i,j]=abs(i-N/2)+abs(j-M/2)
    for k in range(K):
        (x,y)=unravel_index(dist.argmin(),dist.shape)
        dist[x,y]=1000000
        cross[x,y]=1
    cnt = 0
    for i in range(N):
        flag=False
        for j in range(M):
            if cross[i,j]==1:
                if i==0 or j==0 or i==N-1 or j==M-1:
                    cnt +=1
                    flag=True
                    continue
                if i>0 and cross[i-1][j]==0:
                    cnt += 1
                    flag=True
                    continue
                if j>0 and cross[i][j-1]==0:
                    cnt += 1
                    flag=True
                    continue
                if i<N-1 and cross[i+1][j]==0:
                    cnt += 1
                    flag=True
                    continue
                if j<M-1 and cross[i][j+1]==0:
                    cnt += 1
                    flag=True
                    continue


    print 'Case','#'+str(tt)+':',cnt

