#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

translate = None
def getMap():
    global translate
    if translate:
        return translate

    a = "ejp mysljylc kd kxveddknmc re jsicpdrysi" + "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" + "de kr kd eoya kw aej tysr re ujdr lkgc jv" + "qz"
    b = "our language is impossible to understand" + "there are twenty six factorial possibilities" + "so it is okay if you want to just give up" + "zq"
    translate = dict({" ": " "})
    for x, y in map(None, a, b):
        if x in translate and translate[x] != y:
            print "ERROR"
        translate[x] = y

    for i in range(ord('a'), ord('z') + 1):
        ch = chr(i)
        print "%s => %s" % (ch, translate.get(ch))
    return translate

def solve(line):
    translate = getMap()
    result = ""
    for ch in line:
        result = "%s%s" % (result, translate.get(ch))
    return result

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit();

    inFile = open(sys.argv[1])
    outFile = open(sys.argv[2], "w")

    startTime = datetime.datetime.now()
    print "Start Time = %s" % startTime
    print SEPARATE_LINE

    T = int(inFile.readline())
    for i in range(T):
        line = inFile.readline()
        result = solve(line.strip())
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
