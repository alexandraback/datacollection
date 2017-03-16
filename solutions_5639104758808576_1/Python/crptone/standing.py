#f = open('standing.txt', 'r')
f = open('A-large.in', 'r')
g = open('standing.out', 'w')
lines = int(f.readline())
count = 1

while count <= lines:
  line = f.readline().strip().split(' ')
  shy = int(line[0])
  s = line[1]
  print(s)

  clapping = 0
  extra = 0
  for i in range(len(s)):
    n = int(s[i])
    if clapping >= i:
      clapping += n
    else:
      more = i - clapping
      extra += more
      clapping += more + n

  g.write('Case #' + str(count) + ': ' + str(extra) + '\n')
  count += 1
  
f.close()
g.close()
