alpha = set('abcdefghijklmnopqrstuvxwyz')
vowel = set('aeiou')
cons = alpha-vowel

def do(name, n):
  ways = 0
  found = 0
  last = 0
  i = 0
  while i < len(name):
    val = name[i]

    if val in vowel:
      found = 0
    elif found != n:
      found += 1
    
    if found == n:
      begin = i - n + 1
      ways += (begin - last + 1)*(len(name)-i)
      last = i - n + 2

    i += 1

  return ways




cases = int(raw_input())

for case in xrange(1, cases+1):
  name, n = raw_input().split(' ')
  n = int(n)
  res = do(name, n)
  print 'Case #%d: %d' %(case, res)

#  abc defghijklmnopqrstuvxwyz
#  012 34
