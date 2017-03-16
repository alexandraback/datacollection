
def solve(r, c, w):
  count = 0
  if r > 1:
    count += (r - 1) * (c / w)
  count += c / w
  if c % w == 0:
    count += w - 1
  else:
    count += w
  return count



T = input()

for t in range(1, T + 1):
   RCW = raw_input().split(' ')
   r = int (RCW[0])
   c = int (RCW[1])
   w = int (RCW[2])

   print 'Case #%d: %d' % (t, solve(r, c, w))
