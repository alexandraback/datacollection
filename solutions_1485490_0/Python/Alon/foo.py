#!/usr/bin/python
import sys

m = []

def ccc(l):
  ret = []
  for i in l:
    ret.append([i[0], i[1]])
  return ret

def findm(boxes, toys):
  if len(boxes) == 0 or len(toys) == 0:
    return 0
  if boxes[0][1] == toys[0][1]:
    if boxes[0][0] < toys[0][0]:
      new_toys = ccc(toys)
      new_toys[0][0] -= boxes[0][0]
      return boxes[0][0] + findm(boxes[1:], new_toys)
    else:
      new_boxes = ccc(boxes)
      new_boxes[0][0] -= toys[0][0]
      return toys[0][0] + findm(new_boxes, toys[1:])

  return max(findm(boxes[1:], toys), findm(boxes, toys[1:]))


def calc(boxes, toys):
  return findm(boxes,toys)

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  currline = 1
  for j in xrange(1, n+1):
    N,M = [int(x) for x in d[currline].split(' ')]
    data = [int(x) for x in d[currline+1].split(' ')]
    boxes = []
    for i in xrange(len(data)/2):
      boxes.append([data[2*i], data[2*i+1]])
    data = [int(x) for x in d[currline+2].split(' ')]
    toys = []
    for i in xrange(len(data)/2):
      toys.append([data[2*i], data[2*i+1]])
    currline += 3
    print "Case #%d: %d" % (j, calc(boxes, toys))
main()
