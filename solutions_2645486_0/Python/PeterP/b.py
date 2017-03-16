from math import *

def do(acts, engMax,regain,curEng, gain):
    if curEng==0 or len(acts)==0:
        return gain
    #max, do next, don't do next)
    #do next
    maxgain=gain
    for spend in range(0,curEng+1):
        maxgain= \
         max(do(acts[1:],engMax,regain,min(curEng-spend+regain,engMax),gain)\
             +spend*int(acts[0])\
             + gain,maxgain)
         


    #do(acts[1:],engMax,regain,min(curEng+regain,maxEng),gain)
         
    return maxgain

def soln(array,acts):
    e = int(array[0]) #energy max
    r = int(array[1]) #regain
    n = int(array[2]) #num acts

    return do(acts,e,r,e,0)
        
 


#-----------------Main------------------------
                             
def b(filename = "b.in"):
    txt = open(filename, "rU")
    solution = open("solution.txt","w")
    #Read topline info
    topline=txt.readline()
    noCases = int(topline.strip())

    

    
    #For each game:
    for case in range(1,noCases+1):
        caseArr = txt.readline().strip().split(" ") #Chews the line and array<str> it
        acts = txt.readline().strip().split(" ") #Chews the line and array<str> it
        
        solution.write("Case #{0}: {1}\n".format(case, soln(caseArr,acts)) )
        
    txt.close()
    solution.close()
    print "Done"
