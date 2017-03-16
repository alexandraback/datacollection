#!/usr/bin/python
import sys
from sets import Set

ifile=sys.argv[1]
lines=open(ifile).read().split("\n")
tc=lines[0]
lines=lines[1:]
case=1


def bestsort(inp):
    if len(inp) == 1:
        return inp

    newstr=inp[:1]
    inp=inp[1:]

    for c in inp:
        if c < newstr[:1]:
            newstr=newstr+c
        else:
            newstr=c+newstr

    return newstr
            


while lines != [] and lines != ['']:
        line=lines[0]
        output=bestsort(line)
	print("Case #"+str(case)+": "+output)
	lines=lines[1:]
	case+=1
	
	
