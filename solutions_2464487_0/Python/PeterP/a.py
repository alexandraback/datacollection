from math import *

def soln(array):
    r = int(array[0]) #inner radius, for +1 cm

    m = int(array[1])
    used=0
    if (m < 2*(r-1)):
        return 0

    a=float(2)
    b=float(2*r-1)
    c=float(-m)
    #2x^2 + (2r-1)x - m = 0
    res = int( (-b + sqrt (b**2 - 4*a*c))/ (2*a) )
    res+=2

    while m < (2*r - 1) * res + 2* res**2:
        res -=1
    return res
        

        
    


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
