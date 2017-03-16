#!/usr/bin/python
import math
import sys

def main():
        count = int(input());
        for i in range(0, count):
                sys.stdout.write ("Case #" + str(i+1) + ":\n")
                [sR, sC, sM] = input().split(" ");
                (R, C, M) = (int(sR), int(sC), int(sM))

                #print("R: "+str(R))
                #print("C: "+str(C))
                #print("M: "+str(M))
                                
                freeSpaces = (R * C) - M

                if(freeSpaces <= 0):
                        print("Impossible")
                        continue
                elif freeSpaces == 1:
                        for j in range(0,R):
                                for k in range(0,C):
                                        if j == 0 and k == 0:
                                            sys.stdout.write ("c")
                                        else:
                                            sys.stdout.write ("*")                        
                                sys.stdout.write ("\n")
                        continue

                #print("FreeSpaces: "+str(freeSpaces))

                        
                grid = [];
                mathGrid = [];
                visitedGrid = [];
                for j in range(0,R):
                        grid.append([]);
                        mathGrid.append([]);
                        visitedGrid.append([]);
                        for k in range(0,C):
                                grid[j].append(".");
                                mathGrid[j].append(0);
                                
                                visitedGrid[j].append(False);


                activeR = R
                activeC = C

                valid = True;

                while(M > 0):
                    if activeR < activeC:
                        if M >= activeR:
                            for j in range(0,activeR):
                                k = activeC - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            activeC = activeC - 1;
                            M-= activeR
                        elif M == activeR - 1:
                            if activeR == 2:
                                valid = False
                                break
                            if activeR == 3 and activeC == 3:
                                valid = False
                                break
                            #form an L
                            for j in range(2,activeR):
                                k = activeC - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            #the hook at the end
                            j = activeR - 1
                            k = activeC - 2;
                            grid[j][k] = "*";
                            visitedGrid[j][k] = True;
                            for ix in range(j-1,j + 2):
                                    for iy in range(k - 1, k + 2):
                                            if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                    mathGrid[ix][iy] = mathGrid[ix][iy] + 1

                            M = 0
                        else:
                            for j in range(activeR - M,activeR):
                                k = activeC - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            M = 0
                    else:
                        if M >= activeC:
                            for k in range(0,activeC):
                                j = activeR - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            activeR = activeR - 1;
                            M-= activeC
                        elif M == activeC - 1:
                            if activeC == 2:
                                valid = False
                                break
                            if activeC == 3 and activeR == 3:
                                valid = False
                                break
                            #form an L
                            for k in range(2,activeC):
                                j = activeR - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            #the hook at the end
                            k = activeC - 1
                            j = activeR - 2;
                            grid[j][k] = "*";
                            visitedGrid[j][k] = True;
                            for ix in range(j-1,j + 2):
                                    for iy in range(k - 1, k + 2):
                                            if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                    mathGrid[ix][iy] = mathGrid[ix][iy] + 1

                            M = 0
                        else:
                            for k in range(activeC - M,activeC):
                                j = activeR - 1;
                                grid[j][k] = "*";
                                visitedGrid[j][k] = True;
                                for ix in range(j-1,j + 2):
                                        for iy in range(k - 1, k + 2):
                                                if(ix >= 0 and iy >= 0 and ix < R and iy < C):
                                                        mathGrid[ix][iy] = mathGrid[ix][iy] + 1
                            M = 0
                                            
                click = False
                output = ""
                if valid:
                    for j in range(0,R):
                            for k in range(0,C):
                                    if( not click and mathGrid[j][k] == 0):
                                        output+=("c")                        
                                        click = True;
                                    else:
                                        output+= (grid[j][k])                        
                            output+= ("\n")
                if click:
                        sys.stdout.write (output)
                else:
                        print("Impossible");

if __name__ == "__main__":
        main()
