
import sys, string

table = string.maketrans("ynficwlbkuomxsevzpdrjgthaq", "abcdefghijklmnopqrstuvwxyz")
i = sys.stdin

count = int(i.readline())
for j in range(count):
  line = i.readline()

  print "Case #%d: %s" % (j+1,line.translate(table)),



