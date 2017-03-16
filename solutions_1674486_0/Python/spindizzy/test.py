#!/usr/bin/env python2.7

from sys import stdin
import string


# def recurse(classes, path):
#     np = path[-1] # next parent
#     if len(classes[np]) == 0:
#         # Complete path. Done.
#         print(path)
#     else:  
#        for parent in classes[np]:
#            tmp = list(path)
#            tmp.append(parent)
#            recurse(classes, tmp)

visited = set()

def recurse(classes, path):
    global visited
    np = path[-1] # next parent
    if len(classes[np]) == 0:
        # Complete path. Done.
        #print(path)
        return False
    else:  
        for parent in classes[np]:
            tmp = list(path)
            tmp.append(parent)
            if parent in visited:
                return True
            else:
                visited.add(parent)
            if recurse(classes, tmp):
                return True

def isdiamond(classes):
    d = False
    for c in xrange(0,len(classes)):
        global visited
        visited = set()
        if recurse(classes, [c]):
            d = True
    return d

numcases = int(stdin.readline())
for case in xrange(1, numcases+1):
    classes = []
    numclass = int(stdin.readline())
    for c in xrange(0, numclass):
        x = stdin.readline().rstrip().split()
        ni = int(x[0]) # number of inh.
        if ni == 0:
            il = [] # inheritance list
        else:
            il = x[1:] 
        il = map(lambda x: int(x)-1, il)
        classes.append(il)

        #print "Class %d inherits from: %s" % (c, il)

    print "Case #%d: %s" % (case, "Yes" if isdiamond(classes) else "No",)


# vim:set expandtab tabstop=4 shiftwidth=4 softtabstop=4 nowrap:

