import math

def check_containment(trains):
  contained = set()
  all_letters = set(''.join(trains))
  for i, train in enumerate(trains):
    t = train.lstrip(train[0])
    if len(t) == 0:
      continue
    t = t.rstrip(train[-1])
    if len(t) == 0:
      continue
    for l in t:
      contained.add(l)

  for letter in contained:
    count = sum(1 for train in trains if letter in train)
    if count > 1:
      return False

  for letter in all_letters:
    for train in trains:
      if letter in train:
        l = train.index(letter)
        r = train.rfind(letter)
        if train[l:r+1] != letter * (r-l+1):
          return False
  return True

f = open('b_small.txt')
T = int(f.readline())
for turn in range(1, T+1):
  N = int(f.readline().strip())
  trains = f.readline().split()
  # print trains
  possibilities = {}
  letters_left = {}
  letters_right = {}
  possible = check_containment(trains)
  all_letters = set()
  for train in trains:
    all_letters.add(train[0])
    all_letters.add(train[-1])
  all_letters = list(all_letters)

  if possible:
    for c in 'abcdefghijklmnopqrstuvwxyz':
      subset = [train for train in trains if c == train[0] or c == train[-1]]
      if len(subset) == 0:
        continue
      num_all = sum(1 for train in subset if len(set(train)) == 1)

      unique_start = [train for train in subset if train[-1]==c and train[0]!=c]
      unique_end = [train for train in subset if train[0]==c and train[-1]!=c]
      if len(unique_start) > 1:
        possible = False
        break
      if len(unique_end) > 1:
        possible = False
        break
      if len(unique_start) == 1:
        letters_left[c] = unique_start[0][0]
      else:
        letters_left[c] = None
      if len(unique_end) == 1:
        letters_right[c] = unique_end[0][-1]
      else:
        letters_right[c] = None

      possibilities[c] = math.factorial(num_all)

  if possible:
    chains = []
    remaining = set(all_letters)
    while len(remaining) > 0:
      chain = remaining.pop()
      right = chain
      left = chain
      while letters_right[right] != None:
        chain += letters_right[right]
        right = letters_right[right]
        if right not in remaining:
          possible = False
          break
        remaining.remove(right)
      while letters_left[left] != None:
        chain = letters_left[left] + chain
        left = letters_left[left]
        if left not in remaining:
          possible = False
          break
        remaining.remove(left)
      chains.append(chain)
      if not possible:
        break

  if possible:
    poss = []
    for chain in chains:
      p = 1
      for l in chain:
        p *= possibilities[l]
      poss.append(p)
    product = reduce(lambda x, y: x * y, poss, 1)
    print "Case #" + str(turn) + ":", math.factorial(len(chains)) * product
  else:
    print "Case #" + str(turn) + ":", 0