n = 32
k = 500

print('Case #1:')
i = 2**(n-1) + 1
while k > 0:
  s = "{0:b}".format(i)
  proof = []
  for base in range(2, 11):
    x = int(s, base)
    for d in range(2, 101):
      if x % d == 0:
        proof.append(d)
        break
  if len(proof) == 9:
    print(s, " ".join(map(str, proof)))
    k -= 1
  #else:
  #  print(s, "is bad")
  i += 2
