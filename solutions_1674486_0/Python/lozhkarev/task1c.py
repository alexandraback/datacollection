#!/usr/bin/python -tt

import sys
import random
import copy

def DFS(g, ind):
    if g[ind][1]:
        return True
    
    if len(g[ind][0]) == 0:
        g[ind][1] = True
        return False
    
    for child in g[ind][0]:
        r = DFS(g, child)
        if r == True:
            return True

def main():
    f = open('c1-small-attempt0.in')
    out = open('c1-test-out.txt', 'w')
    
    caseNum = int(f.readline())
    
    for tc in range(1, caseNum + 1):
        print 'case #', tc
        
        N = int(f.readline())
        
        G = []
        for i in range(0, N):
            G.append([[], False])
            line = [int(x) for x in f.readline().split()]
            edgeCnt =  line[0]
            line.pop(0)
            for j in range(0, edgeCnt):
                G[i][0].append(line[j] - 1)
        
        #print 'matrix:'
        
        #for el in G:
        #    print el
        
        #print 'end matrix'
        r = False
        for i in range(0, N):
            gcopy = copy.deepcopy(G)
            r = DFS(gcopy, i)
            if r: break
        
        res = 'No'
        if r:        
            res = 'Yes'
            
        out.write('Case #'+str(tc)+': '+res+'\n')
        
    
    out.close()
    
    
    
if __name__ == '__main__':
  main()