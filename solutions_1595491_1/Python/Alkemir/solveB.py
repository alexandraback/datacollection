lines = open('b_small.txt', 'r').read().split('\n')

T = int(lines.pop(0))

for t in range(T):
   count = 0
   toUpgrade = []
   totals = map(int, lines[t].split(' '))
   N = totals.pop(0)
   S = totals.pop(0)
   p = totals.pop(0)

   #Find those which dont need to be surprising
   for total in totals:
      if total % 3 == 0:
         best = total / 3
      elif total % 3 == 1:
         best = ((total - 1) / 3) + 1
      else:
         best = ((total - 2) / 3) + 1
      
      if total == 0:
         best = 0
      
      if best >= p:
         count += 1
      else:
         toUpgrade.append(total)
   
   #Find how many we can upgrade through surprise
   for total in toUpgrade:
      if S == 0:
         break
      
      if total % 3 == 0:
         best = ((total-3) / 3) +2
      elif total % 3 == 1:
         best = ((total - 4) / 3) + 2
      else:
         best = ((total - 2) / 3) + 2

      if total == 0:
         best = 0
         
      if best >= p:
         count += 1
         S -= 1
   
   print 'Case #' + str(t+1) + ': ' + str(count)