#! /usr/bin/python

import sys

def max_cut_height(lawn, target):
  m = None
  for i in range(len(lawn)):
    row_l = lawn[i]
    row_t = target[i]
    for j in range(len(row_l)):
      if row_t[j] < row_l[j]:
	if not m or row_t[j] > m:
	  m = row_t[j]

  return m

def mow_h(lawn, target, entries, cut_height):
  mowed = False
  for i in range(len(lawn)):
    if not entries[i]:
      continue

    for j in range(len(lawn[0])):
      if target[i][j] > cut_height:
	entries[i] = False
	break

    if entries[i]:
      for j in range(len(lawn[0])):
	if lawn[i][j] > cut_height:
	  lawn[i][j] = cut_height
	  mowed = True

  return mowed

def mow_v(lawn, target, entries, cut_height):
  mowed = False
  for i in range(len(lawn[0])):
    if not entries[i]:
      continue

    for j in range(len(lawn)):
      if target[j][i] > cut_height:
	entries[i] = False
	break

    if entries[i]:
      for j in range(len(lawn)):
	if lawn[j][i] > cut_height:
	  lawn[j][i] = cut_height
	  mowed = True

  return mowed

def mow(lawn, target, entries_h, entries_v):
  while lawn != target:
    mowed = False
    cut_height = max_cut_height(lawn, target)
    if cut_height == None:
      break

    mowed = mowed or mow_h(lawn, target, entries_h, cut_height)
    mowed = mowed or mow_v(lawn, target, entries_v, cut_height)
    if not mowed:
      break

  if lawn != target:
    return "NO"
  else:
    return "YES"

def run():
  (N,M) = map(int, sys.stdin.readline().split())
  lawn = []
  target = []
  for i in range(N):
    target.append(map(int, sys.stdin.readline().split()))
    lawn.append([100]*M)

  entries_h = [True]*N
  entries_v = [True]*M

  return mow(lawn, target, entries_h, entries_v)





cases = int(sys.stdin.readline())
for case in range(cases):
  print "Case #%d: %s"%(case+1, run())

