#!/usr/bin/env python3
import sys
import pprint
import argparse
from operator import attrgetter, methodcaller, itemgetter

debug = False
def log(msg, *args):
  global debug
  if debug:
    print(msg.format(*args))

def parse_args():
  parser = argparse.ArgumentParser(description='Google CodeJam Template')
  parser.add_argument('-d', '--debug', action='store_true',
                    help='print debugging messages')
  parser.add_argument('-c', '--case', metavar='N', type=int,
                    help='only run case N (default: run them all)')

  args = parser.parse_args()
  if args.debug:
    global debug
    debug = True
  return args


def solve_brute(a, b, k):
  cnt = 0
  for aa in range(a):
    for bb in range(b):
      if (aa & bb) < k:
        cnt += 1
  return cnt

class Case:
  def __init__(self, i, a, b, k):
    self.i = i
    self.a = int(a)
    self.b = int(b)
    self.k = int(k)

  def solve(self):
    log("Solving: {}", self)
    ans = solve_brute(self.a, self.b, self.k)
    sol = str(ans)
    return self.case() + sol

  def case(self):
    return "Case #{}: ".format(self.i)

  def __repr__(self):
    return self.case()

def parse_input(stream):
  cases = []
  T = int(stream.readline())
  for i in range(1, T+1):
    # parse case input
    a,b,k = stream.readline().split()
    cases.append(Case(i, a,b,k))
  return cases

def main():
  options = parse_args()
  cases = parse_input(sys.stdin)
  for case in cases:
    if not options.case or options.case == case.i:
      print(case.solve())
      sys.stdout.flush()


main()
  
