#!/usr/bin/python
'''
shelajev@gmail.com
'''
import sys
from os.path import abspath
from subprocess import call

def solve(nums):
  maps = {}
  for m in range(1<<20):
    mylist = []
    for i in range(20):
      if (m & (1<<i)) > 0:
        mylist.append(nums[i])
    s = sum(mylist)
    if s in maps:
      return mylist, maps[s]
    maps[s] = mylist
  return None

def main():
  problem = 'C'
  filename = None
  filename = 'input-%s.sample' % problem
  attempt = 0
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
    ans = solve(map(int, line[1:]))
    if ans is None:
      ans = 'Impossible'
    else:
      ans = '\n' + '\n'.join([' '.join(map(str, ans[0])), ' '.join(map(str, ans[1]))])
    msg = 'Case #%s: %s' % (t, ans)
    if filename is None:
      print msg
    output_file.write('%s\n' % msg)
  output_file.close()
  return output_path
    
if __name__ == '__main__':
  output = main()
  print 'Holy Batman! I\'ve just finished crunching it! :)'
  print 'It\'s time to submit!'
  print 'Output file: ', abspath(output)
  call(['cvlc',  'etc/tada.mp3', 'vlc://quit'])