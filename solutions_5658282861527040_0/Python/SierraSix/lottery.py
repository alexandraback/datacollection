import sys
import re
import math

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    num = map(int, r.split(f.readline()[:-1]))
    cases.append({'a': num[0], 'b': num[1], 'k': num[2], 'ab': toBin(num[0]), 'bb': toBin(num[1]), 'kb': toBin(num[2])})
  f.close()
  return cases
def toDec(bin):
  p = 1
  r = range(0, len(bin))
  r.reverse()
  res = 0
  for i in r:
    res += p*int(bin[i])
    p *= 2
  return res
def toBin(dec, n = 0):
  p = 2
  bin = []
  d = dec
  while 1:
    bin[0:0] = [d%2]
    d = d/2
    if d < 1:
      if n <= len(bin):
        break
  return bin
def dostuff():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    case = cases[i]
    pairs = 0
    alen = len(case['ab'])
    blen = len(case['bb'])
    klen = len(case['kb'])
    #maxlen = max(alen, blen, klen)
    #minlen = min(alen, blen, klen)
    for j in xrange(case['a']):
      for k in xrange(case['b']):
        if j&k < case['k']:
          pairs += 1
    out += str(pairs)
    print out
    o.write(out + '\n');
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python stringgame.py <input>'
  else:
    dostuff()
if __name__ == '__main__':
  main()
    
