# codejam 2013 round 1c

# A - consonants

import re

def solve(name, n):
    # brute force for small problem
    searchString = "X"*n
    count = 0
    for start in range(len(name)):
        for end in range(1,len(name)+1):
            if name[start:end].find(searchString)>=0:
                count +=1
    return count

"""
given string like    aaxxxxaaaaaaaaxxxaaa
   relevant info is   2v, 4c, 7v, 3c, 3v
   pass.
"""
def solve2(name,n):
    searchString = "X"*n
    
    if name.find(searchString) <0:
        return 0
    

vowels = re.compile('[aeiou]')
consonants = re.compile("[bcdfghjklmnpqrstvwxyz]")

t = int(raw_input().strip())
for caseNum in range(1,t+1):
    name, n = raw_input().split()
    name = vowels.sub("A", name)
    name = consonants.sub("X", name)
    n = int(n)
    print "Case #" + str(caseNum) + ":", solve(name, n)

    
    

