
import string, os, time, sys

#abcdefghijklmnopqrstuvwxyz

gDict = {}
gDict['a'] = 'y'
gDict['b'] = 'h'
gDict['c'] = 'e'
gDict['d'] = 's'
gDict['e'] = 'o'
gDict['f'] = 'c'
gDict['g'] = 'v'
gDict['h'] = 'x'
gDict['i'] = 'd'
gDict['j'] = 'u'
gDict['k'] = 'i'
gDict['l'] = 'g'
gDict['m'] = 'l'
gDict['n'] = 'b'
gDict['o'] = 'k'
gDict['p'] = 'r'
gDict['q'] = 'z'
gDict['r'] = 't'
gDict['s'] = 'n'
gDict['t'] = 'w'
gDict['u'] = 'j'
gDict['v'] = 'p'
gDict['w'] = 'f'
gDict['x'] = 'm'
gDict['y'] = 'a'
gDict['z'] = 'q'
gDict[' '] = ' '
#ordA = ord('A')

        
    
def HandleCase(f, caseIndex):
    caseline = f.readline().rstrip("\r\n")
    result = ""
    #splitline = caseline.split(" ")
    for c in caseline:
        result += gDict[c]

    header = "Case #%(count)d: %(r)s" % {"count":caseIndex, "r":result}
    print header
    #PrintCharList(result)


inputFile = sys.argv[1]
f = open(inputFile, "r")
numCases = int(f.readline())
for i in range(0, numCases):
    HandleCase(f, i+1)

