##### WARNING: MESSY CODE BELOW #####
# NB Everything could be rewritten into a much shorter (universal) code instead of listing case by case.
attempt = "C-large"

import time
time.clock()

def printno():
  print('Impossible', file=fout)

def printyes(mines, C):
  a = 1
  for i in mines:
    print ( ("c" * a) + ("." * (C-i-a)) + ("*" * i), file=fout)
    a = 0
  return

def solve(R,C,M):
  # Exceptional cases - for 1x and 2x
  mines = list()

  if M == 0:
    mines.extend([0]*R)
    return printyes(mines, C)    

  if M == (R*C)-1:
    mines.extend( [C-1]*1 + [C]*(R-1) )
    return printyes(mines, C)

  if (R < 3) or (C < 3):
    # Cases of 1x
    if (R == 1) or (C == 1):
      if (R*C)-M < 2: return printno()
      else:
        if R == 1: 
          mines.append(M)
          return printyes(mines, C)
        else:
          mines.extend([0] * (R-M) + [1] * M)
          return printyes(mines, C)
      return

    # Cases of 2x
    else:
      if ((R*C)-M < 4) or (((R*C)-M)%2 != 0): return printno()
      else:
        if R == 2: 
          mines.extend([M//2] *2)
          return printyes(mines, C)
        else:
          mines.extend([0] * (R-(M//2)) + [2] * (M//2))
          return printyes(mines, C)
      return

  # Everything else than 1x or 2x below
  noempty = (R*C)-M
  
  # close quarters
  if noempty < 10:

    if noempty == 1:
      mines.extend( [C-1]*1 + [C]*(R-1) )
      return printyes(mines, C)

    if (noempty < 4) or (noempty == 5) or (noempty == 7): return printno()

    if noempty == 4:
      mines.extend( [C-2]*2 + [C]*(R-2) )
      return printyes(mines, C)
    
    if noempty == 6:
      mines.extend( [C-3]*2 + [C]*(R-2) )
      return printyes(mines, C)

    if noempty == 8:
      mines.extend( [C-3]*2 + [C-2]*1 + [C]*(R-3) )
      return printyes(mines, C)

    if noempty == 8:
      mines.extend( [C-3]*2 + [C-2]*1 + [C]*(R-3) )
      return printyes(mines, C)

    if noempty == 9:
      mines.extend( [C-3]*3 + [C]*(R-3) )
      return printyes(mines, C)

  # spacious and easy
  if noempty >= 3*C:

    if M%C == 0:
      mines.extend( [0]*(noempty//C) + [C]*(M//C) )
      return printyes(mines, C)
    if M%C <= (C-2):
      mines.extend( [0]*(noempty//C) + [M%C]*1 + [C]*(M//C) )
      return printyes(mines, C)
    else:
      lastmines = M - (M//C)*C
      if lastmines%2 == 0:
        mines.extend( [0]*((noempty//C)-1) + [lastmines//2]*2 + [C]*(M//C) )
      else: 
        mines.extend( [0]*((noempty//C)-1) + [lastmines//2]*1 + [lastmines//2+1]*1 + [C]*(M//C) )
      return printyes(mines, C)

  # semi-spacious
  else:
    lastmines = M - ((R-3)*C)
    modd = lastmines%3
    minesinc = lastmines//3

    if modd == 0:
      mines.extend( [minesinc]*3 + [C]*(R-3) )
      return printyes(mines, C)
    if modd == 1:
      mines.extend( [minesinc]*2 + [minesinc+1]*1 + [C]*(R-3) )
      return printyes(mines, C)
    else:
      mines.extend( [minesinc]*2 + [minesinc+2]*1 + [C]*(R-3) )
      return printyes(mines, C)

  return


fin = open(attempt + ".in", 'r')
fout = open(attempt + ".out",'w')

numcases = int(fin.readline())

for casenum in range(1,numcases+1):
  R, C, M = (int(n) for n in fin.readline().split())
  print('Case #' + str(casenum) + ':', file=fout)
  solve(R,C,M)

fin.close()
fout.close()
print(time.clock())