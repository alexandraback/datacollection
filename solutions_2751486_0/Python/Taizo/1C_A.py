
# -*- coding: cp932 -*-

import sys

def isVowel(c):
    if c == "a" or c == "i" or c == "u" or c == "e" or c == "o":
        return True
    return False

def isCSeq(subname,num):
    if len(subname) < num:
        return False
    for i in range(num):
        if isVowel(subname[i]):
            return False
    
    return True

#inputfile = "sample.in"
inputfile = "A-small-attempt0.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    line = f.readline().rstrip()
    la = line.split()
    name = la[0]
    n = int(la[1])
    
    begin_pat = 0
    ans = 0
    for i in range(len(name)):
        subname = name[i:len(name)]
        
        begin_pat = begin_pat + 1
        
        if isCSeq(subname,n):
            ans = ans + begin_pat * (len(name) - (i + n) + 1)
            begin_pat = 0
            #print(subname)
              
            
    print("Case #" + str(tc+1) + ": " + str(ans))

