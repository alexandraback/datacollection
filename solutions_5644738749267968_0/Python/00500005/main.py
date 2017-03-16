#!/usr/bin/python3
from googlejam.tools import *
from copy import copy

# its easy, just play the smallest block
# that beats the told one, or play the smallest block
def kens_optimal_strategy(kens, told):
  max_ = max(kens)
  if max_ < told: 
    optimal = min(kens)
    kens.remove(optimal)
    return 1, optimal
  else:
    optimal = min([b for b in kens if b > told])
    kens.remove(optimal)
    return 0, optimal

def war(kens, naomis, fn):
  points = 0
  for told,b_naomi in fn(kens,naomis):
    point,b_ken = kens_optimal_strategy(kens, told)
    #msg("told {:.3f} naomi {:.3f} ken {:.3f}".format(told,b_naomi,b_ken))
    points += point
    assert(b_naomi > b_ken if point else b_naomi < b_ken)
  return points

def nosort(naomis):
  return naomis
def minfirst(naomis):
  l = [b for b in naomis]
  l.sort()
  return l

def truth(kens, naomis):
  for b in naomis:
    yield b, b

def deceit(kens, naomis):
  while True:
    min_ = min(naomis or [None])
    best_ = max(naomis or [None])
    if not min_: break
    kens_worst = min(kens)
    kens_best = max(kens)
    # deplete useless blocks
    if min_ < kens_worst:
      naomis.remove(min_)
      yield kens_best - .0000001, min_
      continue
    # we're in the position to beat ken
    # we'll lie and say our block is better than his best
    # it just has to be better than his worst
    naomis.remove(min_)
    yield 1, min_

class Jam:
  split = " "
  flatten = True
  def cases(ss):
    num_cases = num(ss)
    for i in range(num_cases):
      block_count = num(ss)
      naomis = take(ss,block_count)
      kens = take(ss,block_count)
      kens = {b for b in map(float,kens)}
      naomis = {b for b in map(float,naomis)}
      yield kens,naomis
  def solve(kens, naomis):
    # we can play optimally by playing our smallest blocks first
    # and forcing ken to play is largest blocks
    points_normal = war(copy(kens), copy(naomis), truth)
    #msg("Playing unfair")
    points_deciet = war(copy(kens), copy(naomis), deceit)
    return "{} {}".format(points_deciet, points_normal)
      

import googlejam.main
