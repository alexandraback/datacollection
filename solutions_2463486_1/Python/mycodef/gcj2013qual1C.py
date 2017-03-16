import bisect

prepr = open("preprocessing.txt", "r").readlines()  
prepr = map(lambda x: int(x) ** 2, prepr)
t = int(raw_input())
for i in xrange(1, t + 1):
  a, b = map(int, raw_input().split())
  print "Case #%d: %d" % (i, bisect.bisect_right(prepr, b) - bisect.bisect_left(prepr, a))
