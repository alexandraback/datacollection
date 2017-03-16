#!/usr/bin/python

import sys, datetime, math

SEPARATE_LINE = "=" * 20


def esconsonante(t):
    if t=='a' or t=='e' or t=='i' or t=='o' or t=='u':
	return False
    return True


def solve(line):
    v = line.split()
    string = v[0]
    n = int(v[1])
    tam = len(string)
    ni=0
    nc=0
    nl=0
    nvalue=0
    restar=0
    for i in string:
	nl=nl+1
	if esconsonante(i):
	    nc=nc+1
	else:
	    nc=0
	if nc==n:
	    ni=nl-n-restar
	    nd=tam-nl
	    nvalue = nvalue + (ni+1) + (ni+1)*nd
	    restar = restar + ni+1
	    nc=nc-1
    return nvalue

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
