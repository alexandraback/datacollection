limit = 1000 * 1000 + 7
table = [i for i in xrange(limit)]

for i in xrange(1, limit - 1):
  reversed = int(str(i)[::-1])
  table[i] = table[i-1] + 1
  if reversed < i and i % 10 != 0:
    table[i] = min(table[i], table[reversed] + 1)

for t in xrange(1, 1 + int(raw_input())):
  n = int(raw_input())
  print "Case #{}: {}".format(t, table[n])
