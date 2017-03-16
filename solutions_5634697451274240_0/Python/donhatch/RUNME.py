#!/usr/bin/python

import itertools
import sys

def apply(moves, pancakes):
  scratch = pancakes[:]
  #print "======"
  #print "start: scratch = "+`scratch`
  for move in moves:
    #print "    applying move "+`move`
    assert move >= 1
    assert move <= len(pancakes)
    scratch = [-scratch[move-1-i] for i in xrange(move)] + scratch[move:]
    #print "    scratch = "+`scratch`
  #print "Applied moves "+`moves`+" to pancakes "+`pancakes`+" -> "+`scratch`
  #print "======"
  return scratch

# return minimum number of times needed to execute maneuver to get all +'s
def naive0(input):
  # Brute force:
  # Try all possible sequences of length 0, 1, 2, ...
  # where possible digits are [1,...,nPancakes],
  # i.e. base nPancakes.

  verboseLevel = 0
  if verboseLevel >= 1: print "    input = "+`input`
  nPancakes = len(input)
  # convert to array of +1/-1's
  input = [(1 if c=='+' else -1) for c in input]
  desired_output = [1] * nPancakes
  possibleDigits = range(1, nPancakes+1)
  for length in xrange(1000000):
    if verboseLevel >= 1: print "        Trying length "+`length`
    for possibility in itertools.product(possibleDigits, repeat=length):
      if verboseLevel >= 1: print "            possibility = "+`possibility`
      output = apply(possibility, input)
      if verboseLevel >= 1: print "                output = "+`output`
      if output == desired_output:
        return length
  assert False

# Observations:
#   - If top pancake is -, answer is odd.  If top pancake is +, answer is even.
#   - If first two are -- or ++, answer is same as if first pancake is removed.
#   - Otherwise answer is 1 + answer with first pancake removed.
def smart0(input):
  if input == '': answer = 0
  elif input == '-': answer = 1
  elif input == '+': answer = 0
  elif input[0] == input[1]: answer = smart0(input[1:])
  else: answer = smart0(input[1:]) + 1
  #print "input=%s -> answer=%s" % (input, answer)
  if input != '':
    assert (answer%2==0) == (input[0] == '+')
  return answer

# And in fact... aren't we just counting number of transations from 0 to 1 or back?
# Something like that.
#   - If begins and ends with +: number of internal transitions
#   - If begins and ends with -: number of internal transitions + 1
#   - If begins with + and ends with -: number of internal transitions + 1
#   - If begins with - and ends with +: number of internal transitions
# I.e.
#   - If ends with +: number of internal transitions
#   - If ends with -: number of internal transitions + 1
# I.e. append + and then count internal transitions.

def smart1(input):
  if input == '': return 0
  answer = 0
  for i in xrange(len(input) - 1):
    if input[i] != input[i+1]: answer += 1
  if input[-1] == '-': answer += 1
  return answer

if len(sys.argv) == 2:
  # Print answers so I can see the pattern
  maxLength = int(sys.argv[1])
  for length in xrange(maxLength+1):
    for pancakes in itertools.product('-+', repeat=length):
      pancakes = ''.join(pancakes)
      answerNaive0 = naive0(pancakes)
      print "%s -> %s" % (pancakes, answerNaive0)
else:
  line = sys.stdin.readline().strip()
  nInputs = int(line)
  #print "    nInputs = "+`nInputs`
  for iInput in xrange(nInputs):
    line = sys.stdin.readline().strip()
    #print "        line = "+`line`
    input = line
    answerSmart1 = smart1(input)
    if len(input) <= 5:
      answerNaive0 = naive0(input)
      #print "Case #%s: %s: naive0=%s smart0=%s" % (iInput+1, input, answerNaive0, answerSmart0)
      assert answerNaive0 == answerSmart1
    if len(input) <= 10:
      answerSmart0 = smart0(input)
      assert answerSmart0 == answerSmart1
    print "Case #%s: %s" % (iInput+1, answerSmart1)
