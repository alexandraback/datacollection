# Osmos
for c in xrange(int(raw_input())):
  a, n = map(int, raw_input().split())
  motes = map(int, raw_input().split())
  motes.sort()
  additions = 0
  minmoves = n
  for i in xrange(len(motes)):
    minmoves = min(minmoves, additions + n - i)
    while a <= motes[i]:
      if a == 1: #You cannot add any more size
        break
      a += a - 1
      additions += 1
    else:
      a += motes[i]
      continue
    break
  else:
    minmoves = min(minmoves, additions)
  print "Case #"+str(c+1)+":", minmoves
