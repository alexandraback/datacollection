import sys
data = sys.stdin.readlines()
k = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', 'q': 'z'}
n = 0
for s in data[1:]:
  n+=1
  a = len(s)
  out = []
  for i in range(a):
    if s[i] in k:
      out.append(k[s[i]])
    else:
      out.append(s[i])
  sys.stdout.write('Case #%d: ' % n + ''.join(out))
