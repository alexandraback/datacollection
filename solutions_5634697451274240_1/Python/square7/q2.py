import numpy as np
import string
import sys

f=open(sys.argv[1])
f.readline()
for e,l in enumerate(f):
    ln=string.split(l)[0]
    print "Case #"+str(e+1)+":",
    curr = '+'
    tot=0
    for i in range(len(ln)-1,-1,-1):
        if ln[i]==curr:
            continue
        else:
            if curr=='+':
                curr='-'
            else:
                curr='+'
            tot=tot+1
    print tot
