from string import *
from math import *


def compute(n,m,k, products):
    nums = {2:0,3:0,4:0,5:0}
    isFourPossible = False
    for p in products:
        p = int(p)
        fives = 0
        while p % 5 == 0:
            fives += 1
            p/=5
        if nums[5] < fives:
            nums[5] = fives
            
        sevens = 0
        while p % 3 == 0:
            sevens += 1
            p/=3
        if nums[3] < sevens:
            nums[3] = sevens

        if p % 64 == 0:
            nums[4] = 3
            
        elif p % 32 == 0:
            nums[4] = 2
            nums[2] = 1
            
        elif p % 16 == 0:
            nums[4] = 2
            
        elif p % 8 == 0:
            nums[4] = 1
            
        elif p % 2 == 0:
            nums[2] = 1
            
    s = nums[2] + nums[3] + nums[4] + nums[5]
    if s == 3:
        result = 0
        for d in nums:
            while nums[d] != 0:
                result *= 10
                result += d
                nums[d] -= 1
        return result
    return 245   
            
        
    print nums, isFourPossible

fileName = raw_input("File name: ")
f = open(fileName+".in","r")
g = open(fileName+".out","w")
t = int(f.readline()[:-1])
line = f.readline()[:-1].split()
r = int(line[0])
n = int(line[1])
m = int(line[2])
k = int(line[3])

print "Case #1:"
g.write("Case #1:\n")
for i in range(r):
    line = f.readline()
    line = line[:-1].split()
    compute(n,m,k, line)
    print compute(n,m,k, line)
    g.write("%d\n" %compute(n,m,k, line))
         

g.close()
f.close()


    
    


    
