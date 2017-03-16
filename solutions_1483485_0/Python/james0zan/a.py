c = 0
x = {}
for i in open("xx"):
  if c % 2:
    b = i.strip()
    for j, k in zip(a, b):
      x[j] = k
  else: a = i.strip()
  c+=1
x['z'] = 'q'
x['q'] = 'z'
for i in x:
  print i, x[i]
  
  
c = 0
for i in open("yy"):
  if c != 0:
    s = ""
    for j in i.strip():
      s += x[j]
    print "Case #" + str(c) + ":", s
  c+= 1
