#!/usr/bin/python3

import getopt
import sys
import math

def usage():
    print('''
Options:
-h (--help) 
-v (--verbose)
-f (--input) filename
''')

def bns(N):
    i = 0
    while(N & (1<<i) == 0): i+=1

    return i

def red(N):
    while(N&1 == 0): N >>= 1

    return N

if __name__ == "__main__":

    verbose = False
    fname = "input.txt"

    if sys.version_info[0] < 3:
        print("This script requires Python 3. (You are running %d.%d)" % (
            sys.version_info[0], sys.version_info[1])) 
        sys.exit()

    try:
        opts, args = getopt.getopt(sys.argv[1:], "hvf:",
                                   ["verbose","help","input="])
    except getopt.GetoptError as err:
        print (str(err)) 
        usage()
        sys.exit(2)

    for o, a in opts:
        if o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-f", "--input"):
            fname = a
        else:
            usage()
            sys.exit()


    # reading input
    # first line: number of test cases. T cases follow
    # each test case:

    f = open(fname, "rt")
    ncases = int(f.readline())
    if verbose:
        print("%s: %d cases." % (fname, ncases))

    # input
    for c in range(ncases):
        P,Q =  [int(x) for x in f.readline().split('/')]
        
        a = bns(Q)
        b = red(Q) 


        if verbose:
            print("\n\nCase %d: (%d,%d) : P mod b: %d" % (c+1,P,Q, P % b))
            print("%d %d" %(a,b)) 


        if P % b:
            print("Case #%d: impossible" % (c+1))
            continue

        mylog = math.log(Q/P,2)
        r = math.ceil(mylog)

        print("Case #%d: %d" % (c+1,r))





        

        




