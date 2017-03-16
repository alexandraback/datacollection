nxt = {'i': 'j', 'j': 'k', 'k': 'i'}
def mult(cur, sign, ch):
  if ch == '1':
    return cur, sign
  if cur == '1':
    return ch, sign
  if cur == ch:
    return '1', -sign
  if nxt[cur] == ch:
    return nxt[ch], sign
  return nxt[cur], -sign

def solve():
  L, X = [int(_) for _ in raw_input().split()]
  if X > 16:
    X = 16 + X % 4
  s = raw_input() * X

  one = ('1', 1)
  cur, sign = one
  states = ['i', 'j', 'k', None]
  state = 0
  for ch in s:
#    print cur, sign
#    print 'multiplying %s' % ch
    cur, sign = mult(cur, sign, ch)
    if (cur, sign) == (states[state], 1):
      state += 1
      cur, sign = one

  return states[state] == None and (cur, sign) == one



T = input()
for t in range(1, T + 1):
  print 'Case #%d: %s' % (t, 'YES' if solve() else 'NO')
