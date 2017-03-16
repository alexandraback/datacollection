#!/usr/bin/python
import pdb

def parsedigit(i,s,digits,char,string):
    repeat = True
    while repeat:
        repeat = False
        if char in s:
            # Remove characters in 'ZERO'
            repeat = True
            digits.append(i)
            for ch in string:
                s = s.replace(ch, "", 1)
    return s,digits

def parsedigithelp(i,s,digits):
    if i == 0:
        s,digits = parsedigit(i,s,digits,'Z','ZERO')
    if i == 2:
        s,digits = parsedigit(i,s,digits,'W','TWO')
    if i == 4:
        s,digits = parsedigit(i,s,digits,'U','FOUR')
    if i == 6:
        s,digits = parsedigit(i,s,digits,'X','SIX')
    if i == 8:
        s,digits = parsedigit(i,s,digits,'G','EIGHT')
    if i == 1:
        s,digits = parsedigit(i,s,digits,'O','ONE')
    if i == 3:
        s,digits = parsedigit(i,s,digits,'T','THREE')
    if i == 5:
        s,digits = parsedigit(i,s,digits,'F','FIVE')
    if i == 7:
        s,digits = parsedigit(i,s,digits,'S','SEVEN')
    if i == 9:
        s,digits = parsedigit(i,s,digits,'N','NINE')
    return s, digits

T = input()
testnum = 0
for _ in range(T):
    testnum+=1
    s = raw_input()
    digits = []
    for i in [0,2,4,6,8]:
        s,digits = parsedigithelp(i,s,digits)
    for i in [1,3,5,7]:
        s,digits = parsedigithelp(i,s,digits)
    for i in [9]:
        s,digits = parsedigithelp(i,s,digits)
    ret = ""
    for i in sorted(digits):
        ret+=str(i)
    print "Case #{}: {}".format(testnum, ret)
