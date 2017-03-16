import collections

with open('C-small-attempt2.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()

for i in range(cases):
  n = int(lines[i * 2].strip())
  bffs = map(lambda x: int(x) - 1, lines[i * 2 + 1].strip().split())

  unprocessed = set(range(n))

  maxc = 0
  pairs = set()

  maxending = collections.defaultdict(int) ## maxending[i] = length of max chain (half exclusive/normal) ending at i
  chain = {} ## chain[i] = l, n where l is length of chain from i inclusive, ending at n

  while unprocessed:
    x = unprocessed.pop()
    l = [x]
    s = set([x])
    fr = bffs[x]
    while fr not in s:
      l.append(fr)
      s.add(fr)
      fr = bffs[fr]

    if fr == x and len(l) > 2:
      maxc = max(maxc, len(s))
      for k in l:
        unprocessed.discard(fr)
    elif fr == l[-2]:
      pairs.add((min(l[-1],l[-2]),max(l[-1],l[-2])))
      end = l[-1]
      ef = l[-2]
      for j in range(len(l[:-1])):
        chain[l[j]] = (len(l) - j - 1), end
      chain[end] = 1, ef
      if maxending[ef] < 1:
        maxending[ef] = 1
      if chain[x][0] > maxending[end]:
        maxending[end] = chain[x][0]
      for k in l:
        unprocessed.discard(k)
      
  sch = 0

  for j in pairs:
    sch += maxending[j[0]]
    sch += maxending[j[1]]

  print "Case #" + str(i+1) + ": " + str(max(sch, maxc))
