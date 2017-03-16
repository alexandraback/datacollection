from itertools import combinations

T = int(input())
ln = input().split()
R = int(ln[0]) # num sets
N = int(ln[1]) # num unknown numbers in a set
M = int(ln[2]) # max val of numbers
K = int(ln[3]) # num prods given per set

# enumerate all sets
# for each, enumerate all prods
sets = {}
sets[()] = {}
for i in range(N):
  newsets = {}
  for x in range(2, M+1):
    for s in sets.keys():
      newsets[s+(x,)] = {}
  sets = newsets
#print(sets)

for (s, joints) in sets.items():
  for i in range(len(s)+1):
    for comb in combinations(s, i):
      prod = 1
      for x in comb: prod *= x
      if prod in joints: joints[prod] += 1
      else: joints[prod] = 1
  #print(s, joints)


print("Case #1:")
for t in range(R):
  ln = input().split()
  prods = [int(x) for x in ln]
  best = 0
  bestSet = []
  for (s, joints) in sets.items():
    res = 1
    for prod in prods:
      if prod in joints: res *= prod
      else: res = 0
    if res > best:
      best = res
      bestSet = s
  out = ''
  for num in bestSet: out += str(num)
  print(out)
  #for each possible set
    #take product of conditional prod probabilities
  #print set with max probability
