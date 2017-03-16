def bestword(s):
  if len(s) == 0:
    return ''

  last = 'A'
  lastpos = 0
  for i in range(len(s)):
    if s[i] > last:
      last = s[i]
      lastpos = i

  word = bestword(s[:lastpos])

  for i in s[lastpos:]:
    if i == last:
      word = i + word
    else:
      word = word + i

  return word



with open('A-large.in','r') as f:
    cases=int(f.readline())
    lines=f.readlines()

for i in range(cases):
  print "Case #" + str(i+1) + ": " + bestword(lines[i].strip())
