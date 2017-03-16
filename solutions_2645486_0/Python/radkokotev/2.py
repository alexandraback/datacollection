from string import *
from math import *
def compute(e,r,tasks):
    s = 0
    curr = e 
    for task in tasks:
        s += curr*task
        curr = r
        
    return s

fileName = raw_input("File name: ")
f = open(fileName+".in","r")
g = open(fileName+".out","w")
n = int(f.readline()[:-1])



for i in range(n):
    line = f.readline()
    line = line[:-1].split()
    e = int(line[0])
    r = int(line[1])
    n = int(line[2])
    tasks = f.readline()[:-1].split()
    for j in range(len(tasks)):
        tasks[j] = int(tasks[j])
    tasks = sorted(tasks,reverse = True)
    #print "Case #%d: %d\n" %(i+1, compute(e,r,tasks) )
    g.write("Case #%d: %d\n" %(i+1, compute(e,r,tasks) ))
         

g.close()
f.close()


    
    


    
