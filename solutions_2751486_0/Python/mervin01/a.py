'''
Created on 12/05/2013

@author: George
'''
import re
testfiles = "A-small-attempt0"
imput = open("%s.in" %testfiles).read()
f = open("%s.txt" %testfiles, "a")


class Class():
    def __init__(self):
        pass

lines = imput.split("\n")
countTests = int(lines[0])
iTested = 0
testStartLine = 1

while iTested < countTests:
    #iterate through the tests in input file
    name, n = lines[testStartLine].split(" ")
    nValue = 0
    for start in range(len(name)):
        for stop in range(start+int(n), len(name)+1):
            results = re.findall("[bcdfghjklmnpqrstvwxyz]{%s}" %n, name[start:stop])
            if results != []:
                nValue += 1
#             print name[start:stop], results, len(results)
    print >>f, "Case #%s: %s" %( iTested+1, nValue)
    iTested += 1
    testStartLine += 1




print "DONE!"
