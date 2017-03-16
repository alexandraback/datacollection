#!/usr/bin/env python

import math
import sys


        


if __name__ == '__main__':
    ncases = int(sys.stdin.readline())

    for nc in range(ncases):
        N = int(sys.stdin.readline())


        G = {}
        for n in range(N):
            fields = sys.stdin.readline().split()
            M = int(fields[0])
            
            if M > 0:
                G[n+1] = map(int,fields[1:])
                        
            else:
                G[n+1] = []


               
#        print G 


        #current = G.keys()[0]

        diamond = False 
        for node in G:
                
                current = node
                Q = []
                visitados = [0]*N
                Q.append(current)
                diamond = False
                while not diamond and Q:
                    current = Q.pop()
                    for sig in G[current]:
                        visitados[sig-1] +=1
                        
                        if visitados[sig-1] > 1:
                            diamond = True
                            break
                        Q.append(sig)  
                        
                if diamond:
                     break

        if diamond == True:

            print "Case #%d: Yes"%(nc+1)
        else:

            print "Case #%d: No"%(nc+1)

