import random
from pprint import pprint

def get_divider(n):
  for m in range(2, int(n**0.5)+1):
    if not n%m:
      return m
  return None

def calc(d):
  n = (2 ** (d-1)) + random.randint(0, (2**(d-1))-1)
  s =  "{0:b}".format(n)[:-1] + '1'

  res = [s*2]
  for base in range(2, 10+1):
    t = int(s, base)
    tt = int(s*2, base)
    d = get_divider(t)
    if d:
      res.append(str(d))
      assert t % d == 0
      assert tt % d == 0
    else:
      return 0
  return res

def main():

  res = set()
  while len(res) < 500:

    t = calc(16)
    if t:
      res.add(' '.join(t))
      print t

  pprint(res)



if __name__ == '__main__':
  main()