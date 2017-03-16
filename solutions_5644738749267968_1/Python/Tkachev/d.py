from __future__ import print_function

def solve_fair(n, a, b):
  ans = 0
  for ca in a:
    for cb in b:
      if cb > ca:
        b.remove(cb)
        break
    else:
      ans += 1
      b.remove(b[0])
  return ans

def solve_cheat(n, a, b):
  ans = 0
  for ca in a:
    if ca > b[0]:
      ans += 1
      b.remove(b[0])
    else:
      b.remove(b[-1])
  return ans

if __name__ == '__main__':
  with open('input.txt') as inp, open('output.txt', 'w') as outp:
    test_cases = int(inp.readline())
    for i in range(test_cases):
      n = inp.readline()
      a = sorted([float(x) for x in inp.readline().split()])
      b = sorted([float(x) for x in inp.readline().split()])
      print('Case #%d: %d %d' % (i + 1, solve_cheat(n, a[:], b[:]), solve_fair(n, a[:], b[:])), file=outp)