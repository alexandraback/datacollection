# -*- coding: utf-8 -*-
"""
Created on Fri Apr 15 20:13:52 2016

@author: jo
"""

  

with open('input', 'r') as f:
    with open('output', 'w') as fo:
        cases = int(f.readline())
        print cases
        for case in xrange(1,cases+1):
            fo.write('Case #' + str(case) + ': ')
            print('Case: ' + str(case))
    
            B, M = map(int, f.readline().strip().split())
            if M ==0:
               fo.write("IMPOSSIBLE\n")
            else:
                maxRoutes = B-1
                b = B-3
                while(b>0):
                    maxRoutes +=b
                    b -= 1
                print M
                print maxRoutes
                if(M>maxRoutes):
                        fo.write("IMPOSSIBLE\n")
                else:
                        fo.write("POSSIBLE\n")
                        
                            
                        output = [[0 for x in range(B)] for y in range(B)] 
                        if(M==1):
                            output[0][B-1] = 1
                        else:
                         if(M<B):
                            for i in range(M):
                                output[0][i+1] = 1
                                output[i+1][B-1] = 1
                         else:
                          done = False
                          for i, row in enumerate(output):
                            if done:
                                if(i<(B-1)):
                                  output[i][B-1] = 1
                            else:
                             theseRoutes = 0
                             for j, column in enumerate(row):
                                if((j>i) and(i<(B-1))):
                                    output[i][j] = 1
                                    if(theseRoutes>0 or i == 0):
                                        M -=1
                                    theseRoutes += 1
                                    if M == 0:
                                        done = True
                                        break
                
                        for o in output:
                            out = "".join(str(i) for i in o)
                            fo.write(out)          
                            fo.write('\n')