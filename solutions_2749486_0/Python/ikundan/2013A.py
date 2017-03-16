import os
import math
import types

def main():
    idx = 0
    f = open("B-small-attempt1.in","r")
    #f = open("trial.txt","r")
    doc = f.read().split('\n')   
    num_test_cases = int(doc[idx])
    for i in range(1,(num_test_cases+1)):
        idx = idx + 1
        cord = doc[idx].split(" ")
        x = int(cord[0])
        y = int(cord[1])
        op = ""
        move = 0
        newX = 0
        newY = 0
        if(x>0):
            while(newX < x):
                if(newX+move<x):
                    op = op+'E'
                    move = move+1
                    newX = newX + move
                    #print newX, move
                else:
                    break
            if(not (newX == x)):
                while(not (newX == x)):
                    op = op+'W'
                    move = move+1
                    newX = newX - move
                    op = op+'E'
                    move = move+1
                    newX = newX + move
        else:
            while(newX > x):
                if(newX-move>x):
                    op = op+'W'
                    move = move+1
                    newX = newX - move
                    #print newX, move
                else:
                    break
            if(not (newX == x)):
                #print "-----------------"
                #print x, newX
                while(not (newX == x)):
                    #print newX, move
                    op = op+'E'
                    move = move+1
                    newX = newX + move
                    op = op+'W'
                    move = move+1
                    newX = newX - move
            
                    
            #print "Along X: "+op
        if(y> 0):                
            while(newY < y):
                if(newY+move<y):
                    op = op+'N'
                    move = move+1
                    newY = newY + move
                else:
                    break

            if(not(newY == y)):
                while(not(newY == y)):
                    op = op+'S'
                    move = move+1
                    newY = newY - move
                    op = op+'N'
                    move = move+1
                    newY = newY + move
                #print "Along Y: "+op
        else:
            while(newY > y):
                if(newY-move>y):
                    op = op+'S'
                    move = move+1
                    newY = newY - move
                else:
                    break

            if(newY is not y):
                while(not(newY == y)):
                    op = op+'N'
                    move = move+1
                    newY = newY + move
                    op = op+'S'
                    move = move+1
                    newY = newY - move
                #print "Along Y: "+op
            
        
        print "Case #"+str(i)+": "+op
            
            
if __name__ == "__main__":
    main()

