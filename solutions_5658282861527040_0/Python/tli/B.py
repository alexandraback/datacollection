t = int(raw_input())

for i in xrange(t):
  a, b, k = map(int, raw_input().split(" "))
  count = 0

  for n in xrange(0, a):
    for m in xrange(0, b):
      if n & m < k:
        count += 1

  print "Case #" + str(i + 1) + ":", count