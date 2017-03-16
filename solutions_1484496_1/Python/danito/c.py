#!/usr/bin/python -tt

import itertools

def main(line):
  lst = map(int, line.split(" "))
  N = lst.pop(0)
  dic = {}
  for i in xrange(N):
    for j in itertools.combinations(lst,i):
      tot = 0
      for k in j:
        tot = tot + k
      if dic.get(tot):
        sum1=dic.get(tot)
        sum2=""
        for k in j:
          if sum2 == "": sum2 = str(k)
          else: sum2 = sum2 + " " + str(k)
        res = "\n" + sum1 + "\n" + sum2
        return res
      else:
        val=""
        for k in j:
          if val == "": val = str(k)
          else: val = val + " " + str(k)
        dic[tot] = val
  return "Impossible"




if __name__ == '__main__':
  import sys
  N = int(sys.stdin.readline())
  for i in xrange(N):
    res = main(sys.stdin.readline().strip())
    print "Case #%d:%s" % (i + 1, res)



