NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn)
  R, C, M = [int(x) for x in raw_input().split()]
  RC = R*C
  if R == 1:
    print '*'*M + '.'*(C-M-1) + 'c'
  elif C == 1:
    print '\n'.join(['*']*M + ['.']*(R-M-1) + ['c'])
  elif M == RC-1:
    print '\n'.join(['*'*C]*(R-1))
    print '*'*(C-1) + 'c'
  elif R == 2:
    if M%2 or M == RC-2:
      print "Impossible"
    else:
      print '*'*(M/2) + '.'*(C-M/2)
      print '*'*(M/2) + '.'*(C-M/2-1) + 'c'
  elif C == 2:
    if M%2 or M == RC-2:
      print "Impossible"
    else:
      for i in xrange(M/2):
        print "**"
      for j in xrange(M/2, R-1):
        print ".."
      print ".c"
  elif M == RC-4:
    print '\n'.join(['*'*C]*(R-2))
    print '*'*(C-2) + ".."
    print '*'*(C-2) + ".c"
  elif M == RC-6:
    print '\n'.join(['*'*C]*(R-2))
    print '*'*(C-3) + "..."
    print '*'*(C-3) + "..c"
  elif M < RC-7:
    rows = M/C
    if rows > R-3 >= 0:
      rows = R-3
    leftover = M - rows*C
    columns = leftover / (R-rows)
    leftover %= (R-rows)

    need = 0
    if leftover == R-rows-1:
      need = 1
      leftover -= 2

    if rows > 0:
      print "\n".join(['*'*C]*rows)
    if need:
      print '*'*(columns+2) + '.'*(C-columns-2)
    for i in xrange(leftover):
      print '*'*(columns+1) + '.'*(C-columns-1)
    for i in xrange(R-rows-leftover-need-1):
      print '*'*(columns) + '.'*(C-columns)
    print '*'*(columns) + '.'*(C-columns-1) + 'c'
  else:
    print "Impossible"

