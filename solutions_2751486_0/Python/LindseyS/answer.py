#!/usr/bin/python

import re

try:
        with open("A-small-attempt0.in") as inFile, open("output.txt", "w") as outFile:
                cases = int(inFile.readline().strip())
                for c in range(cases):
                        outFile.write("Case #" + str(c+1) + ": ")
                        firstRow = inFile.readline().split(" ")
                        name = firstRow[0].strip()
                        nValue = int(firstRow[1].strip())
                        position = []
                        substrs = []
                        count = 0
                        last = 0
                        for each in range(0,len(name)):
                                if name[each] != "a" and name[each] != "e" and name[each] != "i" and name[each] != "o" and name[each] != "u":
                                        position.append(each)
                        for each in range(0,len(position)+1-nValue):
                                if position[each+nValue-1] == position[each] + nValue-1:
                                        substrs.append(position[each])
                        count = count + len(substrs)
                        for each in substrs:
                                before = each
                                after = len(name) - (each+nValue)
                                count = count + before-last + after + (before-last)*after
                                last = each+1
                        outFile.write(str(count)+ "\n")
except IOError as err:
        print(str(err))
