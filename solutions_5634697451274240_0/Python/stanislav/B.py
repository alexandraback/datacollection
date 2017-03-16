import sys

def inv(ch):
  return '+' if ch == '-' else '-'

def flip(p, start, stop):
  while start <= stop:
    t = p[start]
    p[start] = inv(p[stop])
    p[stop] = inv(t)
    start += 1
    stop -= 1

def run(t):
  p = raw_input()
  p = list(p + '0')
  ans = 0
  while True:
    last = p[0]
    for i in range(1, len(p)):
      if p[i] == last:
        continue
      elif i < len(p) - 1 or p[i - 1] == '-':
        flip(p, 0, i - 1)
        ans += 1
        break;
      if i == len(p) - 1:
        print('Case #{}: {}'.format(t, ans))
        return

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
