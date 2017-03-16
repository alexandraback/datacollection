T = int(raw_input())

for i in xrange(T):
  # Input data 
  N = int(raw_input())
  Naomi_str = raw_input().split()
  Ken_str = raw_input().split()

  # Working with integers
  Naomi_d_war = []
  for item in Naomi_str:
    #item = int(float(item)*100000)
    Naomi_d_war.append(float(item))
    Naomi_d_war.sort()
    Naomi_war = [item for item in Naomi_d_war]

#  print Naomi

  Ken_d_war = []
  for item in Ken_str:
    #item = int(float(item)*100000)
    Ken_d_war.append(float(item))
    Ken_d_war.sort()
    Ken_war = [item for item in Ken_d_war]
#  print Ken
    
  d_war = 0 # blocks winned by Naomi playing deceitful war
  war = 0   # blocks winned by Naomi playing war
  for j in xrange(len(Naomi_d_war)):
    # d_war play:
    # - Si mi mejor baza no es mejor que su mejor baza, le engano para que gaste su mejor baza (le digo
    #   que la mia es casi tan buena como la suya), pero yo me deshago de mi peor carta....total no podia
    #   ganar esta mano
    if Naomi_d_war[-1] < Ken_d_war[-1]:
      Naomi_d_war.pop(0) # mi peor carta
      Ken_d_war.pop()    # su mejor carta
    # - Si mi mejor baza es mejor que su mejor baza, se lo hago saber, asi que el tira su peor carta,
    #   porque da la mano por perdida, y yo gasta la minima carta que gane (punto y conservo mi mejor carta)
    else:
      found = 0
      for k in xrange(len(Naomi_d_war)):
        if Naomi_d_war[k] > Ken_d_war[0]:
          Naomi_d_war.pop(k)
          Ken_d_war.pop(0)
          d_war += 1 # punto ganado :)
          break

    # war play: ponemos (Naomi) nuestro bloque mas pequeno, y Ken se juega el mas
    # pequeno con el puede ganar
    found = 0
    for k in xrange(len(Ken_war)):
      if Ken_war[k] > Naomi_war[j]:
        Ken_war.pop(k)
        found = 1  
        break
    if found == 0:
      Ken_war.pop(0)
      war += 1

  # Print result
  print 'Case #%d: %d %d' % (i+1, d_war, war)

