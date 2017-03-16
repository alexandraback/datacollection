#!/usr/bin/env python

import sys

def rl():
  return sys.stdin.readline().strip()

def solve_one():
  S=map(int,rl().split())[1:]
  Q=[]
  for i in xrange(len(S)):
    Q.append({})
  Q[0][S[0]]=1
  for i in xrange(1,len(S)):
    for j in Q[i-1]:
      Q[i][j] = 0
      Q[i][j+S[i]] = 1
  def find_seq(s):
    seq=[]
    for i in xrange(len(S)-1,-1,-1):
      if Q[i][s]==1:
        seq.append(S[i])
        s-=S[i]
    return seq[::-1]
  l = len(S)-1
  ret=[]
  for i in Q[l]:
    if 2*i in Q[l]:
      s1 = set(find_seq(i))
      s2 = set(find_seq(2*i))
      s2 = s2-s1
      if sum(s1)==sum(s2):
        ret.append(' '.join(str(x) for x in s1))
        ret.append(' '.join(str(x) for x in s2))
        return '\n' + '\n'.join(ret)
  return '\nImpossible'

def main():
  T = int(rl())
  for i in xrange(T):
    print 'Case #%d: %s' % (i+1,solve_one())

if __name__ == '__main__':
  main()
