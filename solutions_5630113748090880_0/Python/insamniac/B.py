#!/usr/bin/python
import sys
from sets import Set

ifile=sys.argv[1]
lines=open(ifile).read().split("\n")
tc=lines[0]
lines=lines[1:]
case=1



def doit(inp):
    items=[]
    for item in inp:
        x=[int(i) for i in item.split(' ')]
        items.append(sorted(x))

    all=[i for s in items for i in s]
    nums=[]
    for n in range(min(all),max(all)+1):
        c=all.count(n)
        if c % 2 == 1:
            nums.append(n)

    return str(" ".join([str(num) for num in sorted(nums)]))







while lines != [] and lines != ['']:
        soldierCount=int(lines[0])*2 - 1
        lines=lines[1:]
        items=[lines[i] for i in range(soldierCount)]
        output=doit(items)
	print("Case #"+str(case)+": "+output)
	lines=lines[soldierCount:]
	case+=1
	
	
