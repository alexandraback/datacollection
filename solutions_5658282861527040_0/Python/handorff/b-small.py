t = int(raw_input())

a_list = []
b_list = []
k_list = []

for i in xrange(t):
  [a, b, k] = map(int, raw_input().split(' '))
  a_list.append(a)
  b_list.append(b)
  k_list.append(k)

outputs = []
for i in xrange(t):
  a = a_list[i]
  b = b_list[i]
  k = k_list[i]

  count = 0
  for x in xrange(a):
    for y in xrange(b):
      if x & y < k:
        count += 1
  outputs.append("Case #%d: %d" % (i + 1, count))

print '\n'.join(outputs)
