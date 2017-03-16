import sys

def run(t):
  s = raw_input()
  post = []
  pre = []
  for c in s:
    if len(pre) == 0:
      pre.append(c)
    elif c >= pre[-1]:
      pre.append(c)
    else:
      post.append(c)
  pre.reverse()
  print('Case #{}: {}'.format(t, ''.join(pre + post)))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
