#!/usr/bin/python

import sys
maxdepth = 9 
possibles = set([3])
def recurse(num =0, depth = 0):
    if depth == maxdepth:
        strnum = str(num)
        if strnum != strnum[::-1]:  
            return
        possibles.add(num)
        return

    recurse(num * 10 + 0, depth+1)
    recurse(num * 10 + 1, depth+1)
    recurse(num * 10 + 2, depth+1)

def main():
    recurse(0)
    acceptables = set ()
    for possible in possibles:
        square = possible * possible

        strsquare = str(square)

        if strsquare != strsquare[::-1]:
            continue
        acceptables.add(square)


    infile = file (sys.argv[1])

    ncases = int(infile.readline().strip())

    for case in range(1,ncases+1):
        bottom,top = map(int, infile.readline().strip().split())

        print "Case #%d: %d" % (case, len([x for x in acceptables if bottom <= x <= top]))
        

main()
