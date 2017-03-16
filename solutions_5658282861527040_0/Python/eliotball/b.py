input_count = int(raw_input())

for i in xrange(input_count):
  values = [int(value) for value in raw_input().split(" ")]
  count = 0
  for a in xrange(values[0]):
    for b in xrange(values[1]):
      if a & b < values[2]:
        count += 1
  print "Case #" + str(i + 1) + ": " + str(count)
