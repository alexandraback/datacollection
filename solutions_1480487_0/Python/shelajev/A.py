#!/usr/bin/python
'''
shelajev@gmail.com
'''
import sys
from os.path import abspath
from subprocess import call

eps = 1e-12

def isOK(X, score, votes, js):
  found = False
  my = score + X * votes
#  print 'my = ', my
  left = 1 - votes 
  for s in js:
    if s == score and not found:
      found = True #skip myself
      continue
    if s >= my:
      continue
    Vj = (my - s)/X
#    print 'his =', (s + X*Vj)
    if(Vj > left):
#      print 'here!!!'
      return True
    left -= Vj
#  print 'finished, left= ', left
  return left < 0
  

def solve(N, js):
  X = sum(js)
  def solveOne(score):
    lo, hi = 0, 1
    while(hi - lo > eps):
      med = (hi + lo) / 2.0
      if(isOK(X, score, med, js)):
        hi = med
      else:
        lo = med
    if hi < eps:
      hi = 0
    return hi
  return map(lambda x: x*100, map(solveOne, js))
  

def main():
  problem = 'A'
  filename = None
#  filename = 'input-%s.sample' % problem
  attempt = 1
  filename = '%s-small-attempt%s' % (problem, attempt)
#  filename = '%s-large' % problem
  if not filename:
    input_file = sys.stdin
    output_path = 'sample.txt'
  else:
    input_file = open('in/%s.in' % filename, 'r')
    output_path = 'out/%s.out' % filename
  output_file = open(output_path, 'w')
  T = int(input_file.readline().rstrip())
  for t in range(1, T+1):
    line = input_file.readline().rstrip().split()
    ans = solve(int(line[0]), map(float, line[1:]))
    ans = ' '.join(map(str, ans))
    msg = 'Case #%s: %s' % (t, ans)
    if not filename:
      print msg
    output_file.write('%s\n' % msg)
  output_file.close()
  return output_path
    
if __name__ == '__main__':
  output = main()
  print 'Holy Batman! I\'ve just finished crunching it! :)'
  print 'It\'s time to submit!'
  print 'Output file: ', abspath(output)
#  call(['cvlc',  'etc/tada.mp3', 'vlc://quit'])