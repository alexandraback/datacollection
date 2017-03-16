z = []

def check (sa):
  a = int (sa)
  b = a * a
  sb = str (b)
  if sb == sb[::-1]:
#    print (sb + " <- " + sa)
    z.append (b)

for a in range (100000):
  sa = str (a)
  check (sa[:-1:] + sa[::-1])
  check (sa + sa[::-1])

z.sort ()

nt = int (input ())
for tt in range (nt):
  a, b = map (int, input ().split ())
  ans = sum (1 if a <= x and x <= b else 0 for x in z)
  print ("Case #" + str (1 + tt) + ": " + str (ans))
