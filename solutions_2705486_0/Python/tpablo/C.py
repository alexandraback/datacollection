#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os, sys
import math, random
import bisect


IN, OUT = None, None
ged = []
shorties = [set(), set(), set(), set(), set()]
mem = dict()


def ged_starting_with(d, p):
  if p == '':
    for g in d:
      yield g
  else:
    s = bisect.bisect_left(d, p)
    while s < len(d) and d[s].startswith(p):
      yield d[s]
      s += 1


def ged_considerable(w, fe):
  p = w[:5]
  for j in range(len(p)-1):
    if p[:j] in shorties[j]: yield p[:j]
  for g in ged_starting_with(ged, p): yield g
  for i in range(fe, min(5, len(p))):
    t = p[:i] + '_' + p[i+1:]
    for j in range(i, len(p)-1):
      if t[:j] in shorties[j]: yield t[:j]
    for g in ged_starting_with(ged, t): yield g


def could_insert(word, offset, fe_offset, g):
  if len(word) - offset < len(g): return (False, 0, 0)
  le = -5
  errors = 0
  
  for i in range(fe_offset, len(g)):
    if g[i] != word[offset + i]:
      errors += 1
      if i < le + 5: return (False, 0, 0)
      le = i
  
  fe = max(0, 5 - (len(g) - le))
  fe = max(fe, fe_offset - len(g))
  
  return (True, fe, errors)



def calculate_result(word, offset, fe_offset):
  if offset >= len(word): return 0
  if (offset, fe_offset) in mem: return mem[(offset, fe_offset)]
  ret = (len(word) - offset + 4) // 5
  for g in ged_considerable(word[offset:], fe_offset):
    ci = could_insert(word, offset, fe_offset, g)
    if ci[0]:
      ret = min(ret, ci[2] + calculate_result(word, offset + len(g), ci[1]))
  mem[(offset, fe_offset)] = ret
  return ret


def test_case(i):
  mem.clear()
  OUT.write('Case #%d: ' % i)
  word = IN.readline()[:-1]
  result = calculate_result(word, 0, 0)
  OUT.write('%d\n' % result)
  OUT.flush()


def main():
  ged_file = open('new_garbled_email_dictionary.txt', 'rt')
  for l in ged_file:
    w = l[:-1]
    ged.append(w)
    if len(w) < 5:
      shorties[len(w)].add(w)
  ged_file.close()
  
  T = int(IN.readline())
  for i in range(1, T+1):
    test_case(i)


if __name__ == '__main__':
  assert len(sys.argv) == 2
  iname = sys.argv[1]
  oname = '%s.out' % sys.argv[1][:-3]
  IN = open(iname, 'rt')
  OUT = open(oname, 'wt')
  main()
  IN.close()
  OUT.close()
