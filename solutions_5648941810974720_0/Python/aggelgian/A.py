#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import stdin
from  collections import defaultdict

def main():
  ts = int(stdin.readline())
  for i in range(1, ts+1):
    l = stdin.readline().strip()
    sol = solve(l)
    sol = map(str, sorted(sol))
    sol = "".join(list(sol))
    print("Case #%d: %s" % (i, sol))

def solve(l):
  ts = len(l)
  d = defaultdict(int)
  sol = []
  for c in l:
    d[c] += 1
  # 0s
  n = d['Z']
  sol += n * [0]
  ts -= (4 * n)
  d['Z'] -= n
  d['E'] -= n
  d['R'] -= n
  d['O'] -= n
  if ts == 0:
    return sol
  # 6s
  n = d['X']
  sol += n * [6]
  ts -= (3 * n)
  d['S'] -= n
  d['I'] -= n
  d['X'] -= n
  if ts == 0:
    return sol
  # 7s
  n = d['S']
  sol += n * [7]
  ts -= (5 * n)
  d['S'] -= n
  d['E'] -= (2 * n)
  d['V'] -= n
  d['N'] -=  n
  if ts == 0:
    return sol
  # 8s
  n = d['G']
  sol += n * [8]
  ts -= (5 * n)
  d['E'] -= n
  d['I'] -= n
  d['G'] -= n
  d['H'] -= n
  d['T'] -= n
  if ts == 0:
    return sol
  # 5s
  n = d['V']
  sol += n * [5]
  ts -= (4 * n)
  d['F'] -= n
  d['I'] -= n
  d['V'] -= n
  d['E'] -= n
  if ts == 0:
    return sol
  # 4s
  n = d['F']
  sol += n * [4]
  ts -= (4 * n)
  d['F'] -= n
  d['O'] -= n
  d['U'] -= n
  d['R'] -= n
  if ts == 0:
    return sol
  # 2s
  n = d['W']
  sol += n * [2]
  ts -= (3 * n)
  d['T'] -= n
  d['W'] -= n
  d['O'] -= n
  if ts == 0:
    return sol
  # 1s
  n = d['O']
  sol += n * [1]
  ts -= (3 * n)
  d['O'] -= n
  d['N'] -= n
  d['E'] -= n
  if ts == 0:
    return sol
  # 3s
  n = d['H']
  sol += n * [3]
  ts -= (5 * n)
  d['T'] -= n
  d['H'] -= n
  d['R'] -= n
  d['E'] -= (2 * n)
  if ts == 0:
    return sol
  # 9s
  n = d['I']
  sol += n * [9]
  ts -= (4 * n)
  d['N'] -= n
  d['I'] -= n
  d['N'] -= n
  d['E'] -= n
  if ts == 0:
    return sol
  return -1, sol


if __name__=="__main__":
   main()

