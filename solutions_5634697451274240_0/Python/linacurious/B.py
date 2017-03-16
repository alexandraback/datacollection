attempt_list = ['B-test','B-small-attempt0','B-large']
attempt = attempt_list[1]

import time
time.clock()

from operator import itemgetter
from itertools import groupby

def unique_justseen(iterable, key=None):
    return map(next, map(itemgetter(1), groupby(iterable, key)))

def solve(s):
    string_pattern = list(unique_justseen(list(s)))
    flip_times = string_pattern.count("-")*2-(1 if string_pattern[0]=='-' else 0)
    return flip_times

def main():
  fin = open(attempt + '.in', 'r')
  fout = open(attempt + '.out','w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    s = fin.readline()
    fout.write('Case #' + repr(casenum) + ': ' + str(solve(s)) + '\n')

  fin.close()
  fout.close()

main()
print(time.clock())