#!/usr/bin/python

import sys

def equalCol(newPlot, oldPlot, col,nrows):
    for row in range(nrows):
        if newPlot[row][col] != oldPlot[row][col]:
            return False
    return True

if len(sys.argv) != 2:
    print "Usage: ./lawn.py <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
line = 1
for test in range (1, ntests+1):
    info = data[line].strip().split()
    line+=1
    nrows = int(info[0])
    ncols = int(info[1])
    oldPlot = []
    newPlot = []
    valid = True
    for i in range(nrows):
        currentOldRow = []
        currentNewRow = []
        info = data[line].strip().split()
        line += 1
        max = 0
        for j in range(ncols):
            currentOldRow.append(int(info[j]))
            if int(info[j]) > max:
                max = int(info[j])
        for j in range(ncols):
            currentNewRow.append(max)
        newPlot.append(currentNewRow)
        oldPlot.append(currentOldRow)
    for col in range(ncols):
       if not equalCol(newPlot, oldPlot, col, nrows):
           min = 100
           for row in range(nrows):
               if oldPlot[row][col] < min:
                   min = oldPlot[row][col]
           for row in range(nrows):
               if oldPlot[row][col] > min:
                   valid = False
                   break
       if not valid:
           break
    if valid:
        print "Case #%d: YES" % test
    else:
        print "Case #%d: NO" %test
sys.exit(0)
