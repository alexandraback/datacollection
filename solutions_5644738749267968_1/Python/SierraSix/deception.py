import sys
import re

primes = [0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    blocks = int(f.readline())
    naomi = map(float, r.split(f.readline())[:-1])
    ken = map(float, r.split(f.readline())[:-1])
    naomi.sort()
    ken.sort()
    cases.append({'blocks': blocks, 'naomi': naomi, 'ken': ken, 'scoren': 0, 'scorek': 0})
  f.close()
  return cases
def deception():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    # print cases[i]
    naomi = list(cases[i]['naomi'])
    ken = list(cases[i]['ken'])
    merge = naomi + ken
    merge.sort()
    summary = []
    warpoint = dwarpoint = 0
    for t in xrange(cases[i]['blocks'] * 2):
      if (len(naomi) < 1):
        summary.append({'name': 'ken', 'val': ken[0]})
        del ken[0]
        continue
      if (len(ken) < 1):
        summary.append({'name': 'naomi', 'val': naomi[0]})
        del naomi[0]
        continue
      if naomi[0] < ken[0]:
        summary.append({'name': 'naomi', 'val': naomi[0]})
        del naomi[0]
      else:
        summary.append({'name': 'ken', 'val': ken[0]})
        del ken[0]
    naomi = list(cases[i]['naomi'])
    ken = list(cases[i]['ken'])
    for t in xrange(cases[i]['blocks']):
      chosenNaomi = naomi[t]
      chosenKen = 0
      for k in xrange(len(ken)):
        chosenKen = ken[k]
        if (chosenKen > chosenNaomi):
          break
      del ken[k]
      if (chosenNaomi > chosenKen):
        warpoint += 1
    naomi = list(cases[i]['naomi'])
    ken = list(cases[i]['ken'])
    rush = False # When true, naomi will play her heaviest block, otherwise she will play smallest block and tell ken that the block is only 0.000005 kg lighter than ken's heaviest
    for t in xrange(cases[i]['blocks']):
      if not rush:
        k = len(ken) - 1
        rush = True
        while (k >= 0):
          if ken[k] > naomi[k]:
            rush = False
            break
          k -= 1
      if (rush):
        # no need to lie now, do we?
        toldNaomi = chosenNaomi = naomi[len(naomi) - 1]
        del naomi[len(naomi) - 1]
      else:
        # naomi will cheat ken into playing his heaviest
        chosenNaomi = naomi[0]
        del naomi[0]
        toldNaomi = ken[len(ken) - 1] - 0.000005
      chosenKen = 0
      for k in xrange(len(ken)):
        chosenKen = ken[k]
        if (chosenKen > toldNaomi):
          break
      del ken[k]
      if (chosenNaomi > chosenKen):
        dwarpoint += 1
    out += str(dwarpoint) + ' ' + str(warpoint) + '\n'
    print out
    o.write(out);
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python deception.py <input>'
  else:
    deception()
if __name__ == '__main__':
  main()
