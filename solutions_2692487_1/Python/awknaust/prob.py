#!/usr/bin/python
import sys
sys.setrecursionlimit(10000)

def osmos(armin, blobs, i, table):
    if i >= len(blobs):
        return 0
    
    if (armin, i) in table:
        return table[(armin, i)]
    nxt = blobs[i]
    
    if nxt < armin:
        r = osmos(armin + nxt, blobs, i+1, table)
    elif armin == 1:
        r = 1 + osmos(armin, blobs, i+1, table)
    else:
        r = 1 + min(osmos(2*armin - 1, blobs, i, table), osmos(armin, blobs, i+1, table))
    table[(armin, i)] = r
    return r

def main():
    cases = int(raw_input())
    table = {}
    for i in range(cases):
        l1 =  raw_input()
        armin = int(l1.split()[0])
        blob = raw_input()
        blobs = sorted([int(x) for x in blob.split()])
        table.clear()
        s = osmos(armin, blobs, 0, table)
        print "Case #%d: %d" % (i+1, s)

main()
