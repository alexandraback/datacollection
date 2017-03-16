#!/usr/bin/env python
import sys
Map="yhesocvxduiglbkrztnwjpfmaq"#out put of get_transform.py
def transform(x):
    if not(x.islower()):
        return x
    return Map[ord(x)-ord("a")]

fname1=sys.argv[1]
fname2=fname1+".out"
f1=open(fname1)
f2=open(fname2,"w")
f1.readline()
i=1
for line in f1:
    f2.write("Case #"+str(i)+": "+
             "".join([transform(x) for x in line]))
    i+=1
f1.close()
f2.close()
