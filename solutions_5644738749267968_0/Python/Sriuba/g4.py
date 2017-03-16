def last_position(li, el):
  boo = True
  i = len(li) - 1
  while bool and i >= 0:
    if el == li[i]:
      boo = False
      return i
    else:
      i = i - 1

def war(li):
  if li == [True, False]:
    return 1
  elif li == [False, True]:
    return 0
  elif li[0]:
    pos = last_position(li, False)
    return 1 + war(li[1:pos] + li[pos + 1:])
  else:
    pos = li.index(True)
    return war(li[1:pos] + li[pos + 1:])

def dec_war(li):
  if li == [True, False]:
    return 1
  elif li == [False, True]:
    return 0
  elif li[-1]:
    pos = li.index(False)
    return dec_war(li[:pos] + li[pos+1:-1])
  else:
    pos = last_position(li, True) 
    return 1 + dec_war(li[:pos] + li[pos+1:-1])

fi = open("python/input.txt", "r")
fo = open("python/output.txt", "wb")
t = int(fi.readline())

for z in range(0, t):
  num = int(fi.readline())
  naomi = sorted([float(x)for x in fi.readline().split(' ')])
  ken = sorted([float(x)for x in fi.readline().split(' ')])

  all_weights = [] # True means it's Naomi's log
  i = len(naomi) - 1
  j = len(ken) - 1
  while i >= 0 and j >= 0 :
    if naomi[i] > ken[j]: #paziuret cia
      all_weights.append(True)
      i = i - 1
    else:
      all_weights.append(False)
      j = j - 1
  all_weights = all_weights + [True]*(i+1) + [False]*(j+1)
  fo.write(bytes("Case #"+str(z+1) + ": " + str(dec_war(all_weights)) +
    " " + str(war(all_weights)) + "\n", 'UTF-8'))
fi.close()
fo.close()
