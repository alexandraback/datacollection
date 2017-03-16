cases = int(raw_input())
for case in range(1, cases+1):
  levels = int(raw_input())
  b = []
  for x in range(0, levels):
    input = raw_input().split()
    b.append([int(input[0]), int(input[1])])

  change = True
  moves = 0
  stars = 0
  while change == True:
    change = False
    n = []
    for x in b:
      if stars >= x[1]:
        moves += 1
        if x[0] == 1000000:
          stars += 1
        else:
          stars += 2
        change = True
      else:
        n.append(x)

    if change == False and len(n) > 0:
      n = sorted(n, key=lambda x: x[0])
      if stars < n[0][0]:
        break
      l = 0
      v = n[0][0]
      for q in range(0, len(n)):
        if n[q][0] != v:
          break
        if n[q][1] > n[l][1]:
          l = q
      stars += 1
      moves += 1
      n[l][0] = 1000000
      change = True

    b = n

  if len(b) > 0:
    print "Case #" + str(case) + ": Too Bad"
  else:
    print "Case #" + str(case) + ": " + str(moves)
