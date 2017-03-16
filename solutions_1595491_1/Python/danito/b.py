#!/usr/bin/python -tt

def main(line):
  lst = map(int, line.split(" "))
  N = lst.pop(0)
  S = lst.pop(0)
  p = lst.pop(0)

  count_always = 0
  count_never = 0
  count_with_surprise = 0

  for j in lst:
    if j >= p + 2 * max(p-1,0): count_always += 1
    elif j < p + 2 * max(p-2,0): count_never += 1
    else: count_with_surprise += 1
  return count_always + min(S,count_with_surprise)


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    res = main(sys.stdin.readline().strip())
    print "Case #%d: %s" % (i + 1, res) 

