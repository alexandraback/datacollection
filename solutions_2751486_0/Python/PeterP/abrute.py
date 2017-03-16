from math import *

def soln(array):
    name = array[0] #inner radius, for +1 cm

    n = int(array[1]) #length of consectutive cons
    total = 0

    for x in xrange(len(name)):
        for y in xrange(x,len(name)):
            namest=name[x:y+1]
            con=0
            for char in namest:
                if char not in "aeiou":
                    con+=1
                else:
                    con=0
                if con>=n:
                    total+=1
                    break
                    
                
    return total
                
            
            

        

        
    


#-----------------Main------------------------
                             
def a(filename = "a.in"):
    txt = open(filename, "rU")
    solution = open("solution.txt","w")
    #Read topline info
    topline=txt.readline()
    noCases = int(topline.strip())

    

    
    #For each game:
    for case in range(1,noCases+1):
        caseArr = txt.readline().strip().split(" ") #Chews the line and array<str> it
        
        solution.write("Case #{0}: {1}\n".format(case, soln(caseArr)) )
        
    txt.close()
    solution.close()
    print "Done"
