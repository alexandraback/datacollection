#!/usr/bin/env python

import copy

#infile = "A-large.in.txt"
infile = "A-small-attempt2.in.txt"
#infile = "A-sample.in"
outfile = infile.split(".")[0] + ".out"

fsrc = open(infile, "r")
fres = open(outfile, "w")

T = int(fsrc.readline())

N_list = []
visited = []

def check_items(id):
    sum = False
    for parent in N_list[id]:
        if sum:
            return True
        if parent in visited:
            return True
        else:
            visited.append(parent)
            sum = sum or check_items(parent-1)
    return sum

for t in range(T):
    N_list = []
    N = int(fsrc.readline())
    for n in range(N):
        N_list.append([int(value) for value in fsrc.readline().split()][1:])

    result = False
    for i in range(len(N_list)):
        visited = []
        if len(N_list[i]) < 2:
            continue
        else:
            #import pprint
            #pprint.pprint(N_list)
            result = check_items(i)
        if result:
            break

    
    res = "Case #%s: " %(t+1, ) 
    if result:
        res += 'Yes\n'
    else:
        res += 'No\n'
    print res,
    fres.write(res)

fsrc.close()
fres.close()
