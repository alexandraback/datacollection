#! /bin/python

import sys

def main():
  T = int(sys.stdin.readline())
  for tt in range(1,T+1):
    s = sys.stdin.readline().split(' ')
    r = int(s[0])
    t = int(s[1])
    lb = 1
    ub = t
    while ub-lb>1:
      k = (ub+lb)//2
      v = (2*r+1+(k-1)*2)*k
      if v<=t:
        lb = k
      else:
        ub = k
      #print(str(lb)+ ' ' + str(ub) + ' ' + str(k))
    print('Case #' + str(tt) + ': ' + str(lb))

if __name__ == '__main__':
    main()
    