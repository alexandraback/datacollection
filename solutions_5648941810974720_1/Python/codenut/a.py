N = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
U = {'Z': 0, 'W': 2, 'U': 4, 'X': 6, 'G': 8}
V = {'H': 3, 'F': 5} 
W = {'I': 9, 'O': 1, 'V': 7}


def remove(s, t):
  for c in t:
    #print c, t, s
    s.remove(c)
  return s

def get_uniq(s, map):
  t, r = '', []
  has = 1

  while has:
    has = 0
    for i, u in enumerate(map.keys()):
      if u in s:
        s = remove(s, N[map[u]])
        r.append(map[u])
        has = 1

  return s, r


for cas in xrange(int(raw_input())):
  s = sorted(raw_input())
  #print s
  s, a = get_uniq(s, U)
  s, b = get_uniq(s, V) 
  s, c = get_uniq(s, W) 

  print 'Case #%d: %s' % (cas + 1, ''.join(map(str, sorted(a + b + c))))


  
