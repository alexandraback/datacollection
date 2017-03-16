#! /usr/bin/env python
# code.py (@DESC@)
# Maintainer: Matias Larre Borges <matias@larre-borges.com>
# Last Change: 2012 May  5

import sys

def main():
  file = open(sys.argv[1])
  nb_cases = int(file.readline())
  nb_case = 1
  for i in range(nb_cases):
    numbers = file.readline().split(' ')
    N = int(numbers[0])
    t = 0
    sums = {}
    numset = []
    for s in numbers[1:]:
      t = t + int(s)
      numset.append(int(s))
    a = []
    b = []
    for n in numset:
      new_sums = {}
      for k,v in sums.items():
        if k+n in sums:
          eligible = True
          for a in v:
            if a in sums[k+n]:
              eligible = False
          if eligible:
            a = v + [n]
            b = sums[k+n]
            break
        new_sums[k+n] = v + [n]
      if len(a) > 0:
        break
      sums = dict(list(sums.items())+list(new_sums.items()))
      if n in sums:
        a = [n]
        b = sums[n]
        break
      sums[n] = [n]
    sys.stdout.write(("Case #%d: \n" % (nb_case) ))
    if len(a) > 0:
      for n in a:
        sys.stdout.write("%d " % n)
      sys.stdout.write("\n")
      for n in b:
        sys.stdout.write("%d " % n)
      sys.stdout.write("\n")
    else:
      sys.stdout.write("impossible\n")
    nb_case += 1
    file.close

if __name__ == "__main__":
  main()

